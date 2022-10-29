#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include "Estructuras/Cola/Cola.h"
#include "Estructuras/Lista/Lista.h"


using namespace std;


int main() {
    clock_t begin;

    cout << "Comenzando a medir Tiempo\n" << endl;

    begin = clock();

    //empieza el programa





    clock_t end = clock();

    double elapsed_secs = static_cast<double>(end - begin) / CLOCKS_PER_SEC;

    cout << "Tardo elapsed_secs" << elapsed_secs << "\n" << std::endl;

    return 0;


}
