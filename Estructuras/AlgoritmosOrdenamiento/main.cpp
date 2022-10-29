#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <ctime>
#include "./libs.h"

using namespace std;

int main()
{

    fstream fin;
    string aux;
    string algoritmo;

    int *arr;
    int size = 0;
    int opcion;

    fin.open("./arr.txt", ios::in);
    while (getline(fin, aux, ','))
    {
        size++;
    }
    arr = new int[size];

    fin.clear();
    fin.seekg(0, ios::beg);
    for (int i = 0; i < size && getline(fin, aux, ','); i++)
    {
        arr[i] = stoi(aux);
    }

    cout << "Algoritmos de Ordenamiento" << endl;
    cout << "Elija el algoritmo a utilizar para ordenar los valores en arr.txt (" << size << " valores enteros desordenados)" << endl;

    cout << "1. Bubble Sort" << endl;
    cout << "2. Insert Sort" << endl;
    cout << "3. Quick Sort" << endl;
    cout << "4. Shell Sort" << endl;

    cin >> opcion;
    cout << "Ordenando el arreglo con ";

    clock_t inicio = clock();
    switch (opcion)
    {
    case 1:
    {
        algoritmo = "Bubble Sort";
        cout << algoritmo << "..." << endl;
        bubbleSort(arr, size);
    }
    break;
    case 2:
    {
        algoritmo = "Insert Sort";
        cout << algoritmo << "..." << endl;
        insertSort(arr, size);
    }
    break;
    case 3:
    {
        algoritmo = "Quick Sort";
        cout << algoritmo << "..." << endl;
        quickSort(arr, 0, size - 1);
    }
    break;
    case 4:
    {
        algoritmo = "Shell Sort";
        cout << algoritmo << "..." << endl;
        shellSort(arr, size);
    }
    break;
    default:
        cout << "Opcion no valida." << endl;
        break;
    }
    clock_t final = clock();

    cout << "Arreglo ordenado por algoritmo " << algoritmo << endl;
    cout << "Tiempo de ejecucion: " << static_cast<double>(final - inicio) / CLOCKS_PER_SEC << endl;

    opcion = 10;
    while (opcion > 1 || opcion < 0)
    {
        cout << "Desea ver el arreglo ordenado? (1: Si, 0: No): " << endl;
        cin >> opcion;
    }

    if(opcion){
        printArr(arr, size);
    }

    return 0;
}
