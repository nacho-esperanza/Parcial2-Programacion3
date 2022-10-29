#include <iostream>

void quickSort(int *arr, int inicio, int fin)
{
  int i, j, medio;
  int pivot, aux;

  medio = (inicio + fin) / 2;
  pivot = arr[medio];
  i = inicio;
  j = fin;

  do
  {
    while (arr[i] < pivot)
      i++;
    while (arr[j] > pivot)
      j--;

    if (i <= j)
    {
      aux = arr[i];
      arr[i] = arr[j];
      arr[j] = aux;
      i++;
      j--;
    }
  } while (i <= j);

  if (j > inicio)
    quickSort(arr, inicio, j);
  if (i < fin)
    quickSort(arr, i, fin);
}
