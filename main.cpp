#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include "Estructuras/Cola/Cola.h"
#include "Estructuras/Lista/Lista.h"
#include "Estructuras/Arbol/ArbolBinario.h"
#include "Estructuras/Arbol/ArbolBinarioAVL.h"



using namespace std;

struct PalStr {
    int oc;
    string pal;

};

    bool comparePalByValue( PalStr &a, PalStr &b) {
        return (a.oc > b.oc);
    }

    bool compareCpusByProperty1(PalStr &a, PalStr &b) {
        return (a.pal < b.pal);
    }

void printVector(vector<PalStr> &vec)
{
    for (const auto &item : vec) {
        cout << item.pal << " : "
             << item.oc << endl;
    }
    cout << endl;
}

string aMinuscula(string cadena) {
    for (int i = 0; i < cadena.length(); i++) cadena[i] = tolower(cadena[i]);
    return cadena;
}

void Ignorar(vector<PalStr> & Pall, string Palla) {
    Pall.erase(
            std::remove_if(Pall.begin(), Pall.end(), [&](PalStr const & palab) {
                return palab.pal == Palla;
            }),
            Pall.end());
}


int main() {
    string line, pala, oc;
    string pala2, dato, pala3;
    ifstream inMyStream ;
    ifstream Exclutor;
    int let=0,word=0,lin=0,f=0;
    inMyStream.open("C:/Users/santi/Desktop/Prog III/Parcial2-Programacion3/palabras.txt");
    ArbolBinario<string> *arbol1 = new ArbolBinario<string>();
    Cola<string> palabras;
    Cola<string> palabras2;
    Cola<string> palabras3;


    clock_t begin;

    cout << "Comenzando a medir Tiempo\n" << endl;

    // I

    cout << "Ingrese dato" << ':';
    cin >> dato;
    dato = aMinuscula(dato);
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
                    pala = aMinuscula(pala);
                    palabras.encolar(pala);
                    pala="";
                    pala2 = aMinuscula(pala2);
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

    // IV

    Exclutor.open("C:/Users/santi/Desktop/Prog III/Parcial2-Programacion3/Excluir.txt");
    if (Exclutor.is_open())
    {


        while(!Exclutor.eof())
        {
            if(getline(Exclutor,line)){

            }
            for (unsigned int n = 0; n<line.length();n++)
            {

                if (line.at(n) == ' ')
                {
                    pala3 = aMinuscula(pala3);
                    palabras3.encolar(pala3);
                    pala3="";
                }else{
                    pala3+=line.at(n);

                    if(n==line.length()-1){
                        palabras3.encolar(pala3);
                        pala3="";
                    }
                }


            }
        }


    }

    {
        Exclutor.close(); //Cierro el archivo

    }



    vector<PalStr> ej4;
    PalStr Mov;
    string ejPal4[arbol1->gettamanio()];
    int ejOcur4[arbol1->gettamanio()];
    arbol1->OcurEj4(ejPal4, ejOcur4);
    for(int i=0;i<arbol1->gettamanio();i++){
        Mov.pal=ejPal4[i];
        Mov.oc=ejOcur4[i];
        ej4.push_back(Mov);
    }
    while(!palabras3.esVacia()){
        Ignorar(ej4,palabras3.desencolar());
    }
    sort(ej4.begin(),ej4.end(), comparePalByValue);
    printVector(ej4);


    // V
    cout << "Palabra:  " << dato << "--> ocurrencias: " << palabras2.informarOcurrencias(dato);



    begin = clock();

    //empieza el programa



    clock_t end = clock();

    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;

    cout << "\nTardo elapsed_secs " << elapsed_secs << "\n" << std::endl;

    return 0;


}
