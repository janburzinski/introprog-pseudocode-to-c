// gcc src/klausur/algorithmen/practice/alg-practice-bubblesort.c src/klausur/algorithmen/practice/alg-practice-util.c -o builds/alg-practice-bubblesort.exe && ./builds/alg-practice-bubblesort.exe

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alg-practice-util.h"

/**
 *
 * VERGLEICHSBASIERT
 *
 * time complexity: O(n^2)
 * stabil: ja
 *
 * vorgehensweise bei bubblesort:
 * - wir vergleichen immer die zwei nachbar elemente
 *    => also z.B. idx = 0 mit idx = 1
 *
 * hierfür werden zwei loops verwendet:
 * 1. loop: von ersten Element bis arr_size - 1
 * 2. loop: vom ersten ELement bis arr_size - i - 1
 *
 * somit durchlaufen wir den ganzen array, bis er sortiert ist
 *
 */

void bubblesort(int *arr, int arr_size)
{
  for (int i = 0; i < arr_size - 1; i++)
  {
    for (int j = 0; j < arr_size - i - 1; j++) // i = 1; arr_size = 8 => 1 - 8 - 1
    {
      printf("[%d] %d : %d\n", j, arr[j], arr[j + 1]);
      if (arr[j] > arr[j + 1])
        swap(arr, j, j + 1);
    }
  }
}

int main()
{
  int arr[] = {3, 5, 1, 2, 6, 12, 4, 2};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  bubblesort(arr, arr_size);

  print_array(arr, arr_size);

  return 0;
}