#include <ctime>
#include <iostream>


#include <string>
#include <string.h>
#include "Estructuras/Cola/Cola.h"
#include "Estructuras/Lista/Lista.h"
#include "Estructuras/Arbol/ArbolBinario.h"
#include "Estructuras/Arbol/ArbolBinarioAVL.h"
#include <vector>
#include <algorithm>


using namespace std;

struct PalStr{
    int oc;
    string pal;


public:
static bool comparePalByValue(PalStr &a, PalStr &b) {
    return a.oc < b.oc;
}

static bool compareCpusByProperty1(PalStr &a, PalStr &b) {
    return a.pal < b.pal;
}
} typedef PalStr;

void printVector(vector<PalStr> &vec)
{
    for (const auto &item : vec) {
        cout << item.pal << " : "
             << item.oc << endl;
    }
    cout << endl;
}

int main() {
    string line, pala, oc;
    string pala2, dato;
    ifstream inMyStream ;
    int let=0,word=0,lin=0,f=0;
    inMyStream.open("C:/Users/Nacho/Desktop/Parcial2-Programacion3/palabras.txt");
    ArbolBinario<string> *arbol1 = new ArbolBinario<string>();
    ArbolBinario<string> *arbol2 = new ArbolBinario<string>();
    Cola<string> palabras;
    Cola<string> palabras2;
    vector<PalStr> V1;

    clock_t begin;

    cout << "Comenzando a medir Tiempo\n" << endl;

    // I

    cout << "Ingrese dato" << ':';
    cin >> dato;
    cout << endl;

    if (inMyStream.is_open())
    {


        while(!inMyStream.eof())
        {
            if(getline(inMyStream,line)){
                word++;
                lin++;
            }

            int numofChars= line.length();
            for (unsigned int n = 0; n<line.length();n++)
            {

                if (line.at(n) == ' ')
                {
                    numofChars--;
                    word++;
                    palabras.encolar(pala);
                    pala="";
                    palabras2.encolar(pala2);
                    pala2="";

                }else{
                    pala+=line.at(n);
                    pala2+=line.at(n);

                    if(n==line.length()-1){
                        palabras.encolar(pala);
                        pala="";
                        palabras2.encolar(pala2);
                        pala2="";
                    }
                }


            }
            let+=numofChars;
        }


    }

    cout << "Number of characters: "<< let << endl;
    cout << "Number of words: "<< word << endl;
    cout << "Number of lines: "<< lin << endl;

    {
        inMyStream.close(); //Cierro el archivo

    }

    // II y III
    while(!palabras.esVacia()){
        arbol1->put(palabras.desencolar());
    }
    arbol1->tamanio();
    arbol1->inorder();

    // IV CREAR 2 VECTORES, 1 PARA PALABRAS, OTRO PARA OCURRENCIAS Y DESPUES ORDENAR CON SORT DE LA PAGINA.


    // V
    cout << "La cantidad de veces que aparece la palabra " << dato << " es " << palabras2.informarOcurrencias(dato);



    begin = clock();

    //empieza el programa



    clock_t end = clock();

    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;

    cout << "\nTardo elapsed_secs " << elapsed_secs << "\n" << std::endl;

    return 0;


}
