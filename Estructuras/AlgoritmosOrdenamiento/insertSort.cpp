#include <iostream>

void insertSort(int *arr, int size)
{
  int j, aux;

  for (int i = 0; i < size; i++)
  {

    j = i;
    aux = arr[i];

    while (j > 0 && aux < arr[j - 1])
    {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = aux;
  }
}
