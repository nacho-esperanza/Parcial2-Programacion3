#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Estructuras/Cola/Cola.h"
#include "Estructuras/Lista/Lista.h"
#include "Estructuras/Arbol/ArbolBinario.h"
#include "Estructuras/Arbol/ArbolBinarioAVL.h"


using namespace std;


int main() {
    string line, pala, ex;
    ifstream inMyStream ;
    int let=0,word=0,lin=0,f=0;
    inMyStream.open("C:/Users/santi/Desktop/Prog III/Parcial2-Programacion3/palabras.txt");
    ArbolBinario<string> *arbol1 = new ArbolBinario<string>();
    Cola<string> palabras;

    clock_t begin;

    cout << "Comenzando a medir Tiempo\n" << endl;

    // I

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
                }else{
                    pala+=line.at(n);

                    if(n==line.length()-1){
                        palabras.encolar(pala);
                        pala="";
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

    // III
    while(!palabras.esVacia()){
        arbol1->put(palabras.desencolar());
    }
    arbol1->inorder();



    begin = clock();

    //empieza el programa



    clock_t end = clock();

    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;

    cout << "\nTardo elapsed_secs " << elapsed_secs << "\n" << std::endl;

    return 0;


}
