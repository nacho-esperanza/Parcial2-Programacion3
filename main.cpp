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

//-palabras [n]: Mostrará las n primeras palabras en orden alfabético. Si n no
// es ingresado o vale 0, mostrará todas las palabras
//-ocurrencias [n]: Mostrará las n palabras y la cantidad de ocurrencias de c/u
// ordenadas de mayor a menor por ocurrencia. Si n no es ingresado o vale 0,
// mostrará todas las palabras
//-mostrar [palabra],[palabra] : Mostrará la o las palabras pasadas como
// argumento ordenadas por ocurrencia.
//-excluir [palabra],[palabra] : Modifica los comandos ocurrencias y palabras
// haciendo que no muestren las palabras pasadas como argumentos.
//-excluirf [archivo.txt] : Modifica los comandos ocurrencias y palabras
// haciendo que no muestren las palabras que contiene el archivo.txt.

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
    inMyStream.open("C:/Users/Nacho/Documents/Parcial2-Programacion3/palabras.txt");
    ArbolBinario<string> *arbol1 = new ArbolBinario<string>();
    ArbolBinario<string> *arbol2 = new ArbolBinario<string>();
    Cola<string> palabras;
    Cola<string> palabras2;
    Cola<string> palabras3;


    int op;

    string caracts = ",“”.;:'""-*+^=&%#$?¡¿!{[}]()";


    clock_t begin;

    //empieza el programa

    cout << "Comenzando a medir Tiempo\n" << endl;

    cout<< "Ingrese Opcion\n 1) Para a. Contar Caracteres - b. Contar Palabras - c. Contar lineas\n 2)Indicar cuantas palabras diferentes hay en el texto.\n 3)Mostrar las palabras diferentes en orden alfabetico.\n4)Mostrar las palabras diferentes en orden de más ocurrencias. Se puede informar un grupo de palabras a ignorar mediante otro archivo de texto.\n 5)Informar la cantidad de veces que aparece una palabra en el texto." << endl;
    cin >> op;

    // I


    switch(op){
        case 1:
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
                            for (char c: caracts) {
                                pala.erase(remove(pala.begin(), pala.end(), c), pala.end());}
                            pala = aMinuscula(pala);
                            palabras.encolar(pala);
                            pala="";
                            for (char c: caracts) {
                                pala2.erase(remove(pala2.begin(), pala2.end(), c), pala2.end());}
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

            cout << "Numero de caracteres: "<< let << endl;
            cout << "Numero de palabras: "<< word << endl;
            cout << "Numero de lineas: "<< lin << endl;

            {
                inMyStream.close(); //Cierro el archivo

            }
            break;

        case 2:
            // II y III
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
                            for (char c: caracts) {
                                pala.erase(remove(pala.begin(), pala.end(), c), pala.end());}
                            pala = aMinuscula(pala);
                            palabras.encolar(pala);
                            pala="";
                            for (char c: caracts) {
                                pala2.erase(remove(pala2.begin(), pala2.end(), c), pala2.end());}
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

            while(!palabras.esVacia()){
                arbol1->put(palabras.desencolar());
            }
            arbol1->tamanio();

            break;

        case 3:
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
                            for (char c: caracts) {
                                pala.erase(remove(pala.begin(), pala.end(), c), pala.end());}
                            pala = aMinuscula(pala);
                            palabras.encolar(pala);
                            pala="";
                            for (char c: caracts) {
                                pala2.erase(remove(pala2.begin(), pala2.end(), c), pala2.end());}
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
            while(!palabras.esVacia()){
                arbol1->put(palabras.desencolar());
            }
            arbol1->inorder();

            break;

        case 4:

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
                            for (char c: caracts) {
                                pala.erase(remove(pala.begin(), pala.end(), c), pala.end());}
                            pala = aMinuscula(pala);
                            palabras.encolar(pala);
                            pala="";
                            for (char c: caracts) {
                                pala2.erase(remove(pala2.begin(), pala2.end(), c), pala2.end());}
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


            {
                inMyStream.close(); //Cierro el archivo

            }



            Exclutor.open("C:/Users/Nacho/Documents/Parcial2-Programacion3/Excluir.txt");
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

            while(!palabras.esVacia()){
                arbol2->put(palabras.desencolar());
            }


            vector<PalStr> ej4;
            PalStr Mov;
            string ejPal4[arbol2->gettamanio()];
            int ejOcur4[arbol2->gettamanio()];
            arbol2->OcurEj4(ejPal4, ejOcur4);
            for(int i=0;i<arbol2->gettamanio();i++){
                Mov.pal=ejPal4[i];
                Mov.oc=ejOcur4[i];
                ej4.push_back(Mov);
            }
            while(!palabras3.esVacia()){
                Ignorar(ej4,palabras3.desencolar());
            }
            sort(ej4.begin(),ej4.end(), comparePalByValue);
            printVector(ej4);


            break;

        case 5:

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
                            for (char c: caracts) {
                                pala.erase(remove(pala.begin(), pala.end(), c), pala.end());}
                            pala = aMinuscula(pala);
                            palabras.encolar(pala);
                            pala="";
                            for (char c: caracts) {
                                pala2.erase(remove(pala2.begin(), pala2.end(), c), pala2.end());}
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

            cout << "Ingrese dato" << ':';
            cin >> dato;
            dato = aMinuscula(dato);
            cout << endl;

            cout << "La palabra: " << dato << " tiene " << palabras2.informarOcurrencias(dato)<< " ocurrencias.";
            break;
    }





    begin = clock();





    clock_t end = clock();

    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;

    cout << "\nTardo elapsed_secs " << elapsed_secs << "\n" << std::endl;

    return 0;


}
