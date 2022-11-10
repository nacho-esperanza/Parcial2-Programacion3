#ifndef U05_ARBOL_ARBOL_ARBOLBINARIO_H_
#define U05_ARBOL_ARBOL_ARBOLBINARIO_H_

#include "NodoArbol.h"


template <class T>
class ArbolBinario
{
protected:
  NodoArbol<T> *root;
  int tam=0;

public:
  ArbolBinario();

  void put(T data);

  T search(T data);

  void remove(T data);

  void preorder();

  void inorder();

  void postorder();

  ~ArbolBinario();

  bool esVacio();

  void print();

  void tamanio();

  int gettamanio();

    void OcurEj4(T Palabras[],int ocur[]);

private:
  T search(T data, NodoArbol<T> *r);
  NodoArbol<T> *put(T data, NodoArbol<T> *r);
  NodoArbol<T> *remove(T data, NodoArbol<T> *r);
  NodoArbol<T> *findMaxAndRemove(NodoArbol<T> *r, bool *found);
  void preorder(NodoArbol<T> *r);
  void inorder(NodoArbol<T> *r);
  void postorder(NodoArbol<T> *r);
  void OcurEj4(T Palabras[],int ocur[],NodoArbol<T> *r, int& n);
};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template <class T>
ArbolBinario<T>::ArbolBinario() { root = nullptr; }

/**
 * Destructor del Arbol
 */
template <class T>
ArbolBinario<T>::~ArbolBinario() {}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template <class T>
T ArbolBinario<T>::search(T data)
{
  return search(data, root);
}

template <class T>
T ArbolBinario<T>::search(T data, NodoArbol<T> *r)
{
  if (r == nullptr)
  {
    throw 404;
  }

  if (r->getData() == data)
  {
    return r->getData();
  }

  if (r->getData() > data)
  {
    return search(data, r->getLeft());
  }
  else
  {
    return search(data, r->getRight());
  }
}

/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template <class T>
void ArbolBinario<T>::put(T data) { root = put(data, root); tam++;}

template <class T>
NodoArbol<T> *ArbolBinario<T>::put(T data, NodoArbol<T> *r)
{
  if (r == nullptr)
  {
    return new NodoArbol<T>(data);
  }

  if (r->getData() == data)
  {
      r->ocur();
      tam--;
      return r;
  }

  if (r->getData() > data)
  {
    r->setLeft(put(data, r->getLeft()));
  }
  else
  {
    r->setRight(put(data, r->getRight()));
  }

  return r;
}

/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template <class T>
void ArbolBinario<T>::remove(T data)
{
  root = remove(data, root);
}

template <class T>
NodoArbol<T> *ArbolBinario<T>::remove(T data, NodoArbol<T> *r)
{
  NodoArbol<T> *aux;

  if (r == nullptr)
  {
    throw 404;
  }

  if (r->getData() == data)
  {

    if (r->getLeft() == nullptr && r->getRight() == nullptr)
    {
      delete r;
      return nullptr;
    }
    else if (r->getLeft() != nullptr && r->getRight() == nullptr)
    {
      aux = r->getLeft();
      delete r;
      return aux;
    }
    else if (r->getLeft() == nullptr && r->getRight() != nullptr)
    {
      aux = r->getRight();
      delete r;
      return aux;
    }
    else if (r->getLeft() != nullptr && r->getRight() != nullptr)
    {

      if (r->getLeft()->getRight() != nullptr)
      {
        // Aca tenemos que buscar el valor maximo
        bool found;
        aux = findMaxAndRemove(r->getLeft(), &found);
        aux->setRight(r->getRight());
        aux->setLeft(r->getLeft());
      }
      else
      {
        aux = r->getLeft();
        r->getLeft()->setRight(r->getRight());
      }
      delete r;
      return aux;
    }
  }
  else if (r->getData() > data)
  {
    r->setLeft(remove(data, r->getLeft()));
  }
  else
  {
    r->setRight(remove(data, r->getRight()));
  }

  return r;
}

template <class T>
NodoArbol<T> *ArbolBinario<T>::findMaxAndRemove(NodoArbol<T> *r, bool *found)
{
  NodoArbol<T> ret;
  *found = false;

  if (r->getRight() == nullptr)
  {
    *found = true;
    return r;
  }

  ret = findMaxAndRemove(r->getRight(), found);
  if (*found)
  {
    r->setRight(nullptr);
    *found = false;
  }

  return ret;
}

/**
 * Informa si un árbol esta vacío
 * @return
 */
template <class T>
bool ArbolBinario<T>::esVacio() { return root == nullptr; }

/**
 * Recorre un árbol en preorden
 */
template <class T>
void ArbolBinario<T>::preorder()
{
  preorder(root);
  std::cout << std::endl;
}

template <class T>
void ArbolBinario<T>::preorder(NodoArbol<T> *r)
{
  if (r == nullptr)
  {
    return;
  }

  std::cout << r->getData() << " ";
  preorder(r->getLeft());
  preorder(r->getRight());
}

/**
 * Recorre un árbol en orden
 */
template <class T>
void ArbolBinario<T>::inorder()
{
  inorder(root);
  std::cout << std::endl;
}

template <class T>
void ArbolBinario<T>::inorder(NodoArbol<T> *r)
{
  if (r == nullptr)
  {
    return;
  }

  inorder(r->getLeft());
  std::cout << r->getData() << " ";
  inorder(r->getRight());
}

/**
 * Recorre un árbol en postorden
 */
template <class T>
void ArbolBinario<T>::postorder()
{
  postorder(root);
  std::cout << std::endl;
}

template <class T>
void ArbolBinario<T>::postorder(NodoArbol<T> *r)
{
  if (r == nullptr)
  {
    return;
  }

  postorder(r->getLeft());
  postorder(r->getRight());
  std::cout << r->getData() << " ";
}

/**
 * Muestra un árbol por consola
 */
template <class T>
void ArbolBinario<T>::print()
{
  if (root != NULL)
    root->print(false, "");
}

// Se crea funcion tamanio() que nos dice cuantas palabras diferentes tiene el Arbol.

template <class T>
void ArbolBinario<T>::tamanio() {
    cout<<"El archivo tiene "<<tam<<" palabras diferentes\n";
}

// Funcion gettamanio() retorna la cantidad de nodos que tiene el arbol.

template <class T>
int ArbolBinario<T>::gettamanio() {
    return tam;
}

// Metodo que recorre el arbol en modo InOrder para poner en los vectores Palabras[] y ocur[], sus respectivos valores.

template <class T>
void ArbolBinario<T>::OcurEj4(T Palabras[],int ocur[])
{
    int a=0;
    OcurEj4(Palabras,ocur,root,a);


}

// Metodo que recorre el arbol en modo InOrder para poner en los vectores Palabras[] y ocur[], sus respectivos valores.
// n sirve para saber la posicion en la que estas en el arbol de modo inOrder.

template <class T>
void ArbolBinario<T>::OcurEj4(T Palabras[],int ocur[],NodoArbol<T> *r,int& n)
{
    if (r == nullptr)
    {
        return;
    }

    OcurEj4(Palabras,ocur,r->getLeft(),n);
    Palabras[n]=r->getData();
    ocur[n]=r->getocur();
    n++;
    OcurEj4(Palabras,ocur,r->getRight(),n);
}



#endif // U05_ARBOL_ARBOL_ARBOLBINARIO_H_
