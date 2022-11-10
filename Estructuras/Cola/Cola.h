#ifndef U04_COLAS_COLA_COLA_H_
#define U04_COLAS_COLA_COLA_H_

#include "nodo.h"

/**
 * Clase que implementa una Cola generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T>
class Cola
{
private:
  Nodo<T> *tope, *fondo;

public:
  Cola();

  ~Cola();

  void encolar(T dato);

  T desencolar();

  bool esVacia();

  T peek();

    int informarOcurrencias(std::string dato);
};

/**
 * Constructor de la clase Cola
 * @tparam T
 */
template <class T>
Cola<T>::Cola()
{
  tope = nullptr;
  fondo = nullptr;
}

/**
 * Destructor de la clase Cola, se encarga de liberar la memoria de todos los
 * nodos utilizados en la Cola
 * @tparam T
 */
template <class T>
Cola<T>::~Cola()
{
  while (!esVacia())
  {
    desencolar();
  }

  delete tope;
  delete fondo;
}

/**
 * Inserta un dato en la Cola
 * @tparam T
 * @param dato  dato a insertar
 */
template <class T>
void Cola<T>::encolar(T dato)
{
  Nodo<T> *nuevo = new Nodo<T>();
  nuevo->setDato(dato);
  nuevo->setSiguiente(nullptr);

  if (esVacia())
  {
    tope = nuevo;
  }
  else
  {
    fondo->setSiguiente(nuevo);
  }

  fondo = nuevo;
}

/**
 * Obtener el dato de la Cola
 * @tparam T
 * @return dato almacenado en el nodo
 */
template <class T>
T Cola<T>::desencolar()
{
  if (esVacia())
  {
    throw 400;
  }

  T dato = tope->getDato();
  Nodo<T> *aBorrar = tope;
  tope = tope->getSiguiente();

  if (tope == nullptr)
  {
    fondo = nullptr;
  }

  delete aBorrar;
  return dato;
}

/**
 * Responde si la Cola se encuentra Vacía
 * @tparam T
 * @return
 */
template <class T>
bool Cola<T>::esVacia()
{
  return fondo == nullptr;
}

/**
 * Obtener el dato de la Cola sin eliminar el nodo
 * @tparam T
 * @return dato almacenado en el nodo
 */
template <class T>
T Cola<T>::peek()
{
  if (esVacia())
  {
    throw 400;
  }

  return tope->getDato();
}

/**
 * Informar la cantidad de veces que aparece una o un grupo de palabras solicitadas por el usuario.
 *
 * @param ocurrencia
 * @param dato
 */
template<class T>
int Cola<T>::informarOcurrencias(std::string dato) {
    /*Método creado modificando el método del 1er parcial */
    Nodo<T> *nodoOcurrencia = tope;

    int contador = 0;

    if (nodoOcurrencia == nullptr) {//Cola vacia!
        throw 400;
    }

    if (dato == " ") {//Modificado de remover!!
        throw 400;
    } else {

        while (nodoOcurrencia != nullptr) {

            if (dato == nodoOcurrencia->getDato()) {
                contador++;
            }
            nodoOcurrencia = nodoOcurrencia->getSiguiente();
        }

        if (nodoOcurrencia == nullptr) {//final cola
            return contador;

        }
    }
}

#endif // U04_COLAS_COLA_COLA_H_
