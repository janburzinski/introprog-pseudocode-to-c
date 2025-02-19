#include <stdio.h>
#include <stdlib.h>

/**
 *
 * Idee:
 * Wir vergleich zuerst die letzte Ziffer einer Zahl und verteilen diese dann in "Buckets",
 * das gleiche machen wir dann für die Ziffer links von der letzten,...
 *
 * Am Ende sollen wir dann einen Sortierten Array erhalten
 *
 */

int get_max(int *arr, int arr_size)
{
  int max = arr[0];
  for (int i = 0; i < arr_size; i++)
  {
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}

void counting_sort(int *arr, int arr_size, int number)
{
  int *arr_out = (int *)malloc(arr_size * sizeof(int));
  int count[10] = {0};

  free(arr_out);
}

void radixsort(int *arr, int arr_size)
{
}

void main()
{

  return 0;
}