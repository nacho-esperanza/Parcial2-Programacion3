#include <iostream>

void bubbleSort(int *arr, int size)
{
  int aux;
  bool seguir = true;

  for (int i = 0; i < size - 1 && seguir; i++)
  {
    seguir = false;
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        seguir = true;
        aux = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = aux;
      }
    }
  }
}
