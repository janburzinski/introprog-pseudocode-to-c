// gcc src/klausur/algorithmen/count-sort.c -o builds/count-sort.exe && ./builds/count-sort.exe

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * count array aussehen beispiel:
 * [0] 0
 * [1] 0
 * [2] 0
 * [3] 0
 * [4] 0
 * [5] 0
 * [6] 0
 * [7] 0
 * [8] 0
 * [9] 0
 * [10] 0
 * [11] 2
 * [12] 1
 *
 * => 11 wäre also zuerst im array, danach die 12 und so weiter
 *    - dies funktioniert, da die while loop (count[k] > 0) durch alle elemente durchgeht von 0 an, weil k von 0 bis max geht
 *      und wir dann einfach aufsteigend sortieren sozusagen
 */

void count_sort(int *arr_in, int *arr_out, int arr_len)
{
  // größte vorkommende zahl ermitteln
  // diese zahl brauchen wir, damit wir genug speicher für jede vorkommende zahl allokieren können
  int max = arr_in[0];
  for (int i = 1; i < arr_len; i++)
  {
    if (arr_in[i] > max)
      max = arr_in[i];
  }

  // calloc wird anstelle von malloc verwendet, damit wir den int array nicht mit einer zufälligen zahl initialisieren, sondern mit 0
  int *count = (int *)calloc((max + 1), sizeof(int));

  // vorkommen zählen
  for (int i = 0; i < arr_len; i++)
  {
    count[arr_in[i]]++;
  }

  // array wieder konstruieren, basierend auf den gezählten werten
  int idx = 0;
  for (int k = 0; k <= max; k++)
  {
    while (count[k] > 0)
    {
      arr_out[idx++] = k; // zahl in array einfügen
      count[k]--;         // vorkommnisse senken
    }
  }

  free(count);
}

void count_sort_reverse(int *arr_in, int *arr_out, int arr_size)
{
  int max = arr_in[0];
  for (int i = 1; i < arr_size; i++)
  {
    if (arr_in[i] > max)
      max = arr_in[i];
  }

  int *count = (int *)calloc(max + 1, sizeof(int));
  if (count == NULL)
    return;

  // zählen
  for (int i = 0; i < arr_size; i++)
    count[arr_in[i]]++;

  // wieder zusammensetzen basierend auf dem gezählten count array
  int arr_idx = 0;
  for (int k = max; k >= 0; k--) // größte zahlen zuerst einfach mal diggiiii
  {
    // alle zahlen durchgehen, solange count[k] > 0
    while (count[k] > 0)
    {
      arr_out[arr_idx++] = k;
      count[k]--;
    }
  }
}

int main()
{
  int arr[] = {8, 15, 3, 14, 7, 6, 18, 19};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  int *arr_out = (int *)malloc(arr_size * sizeof(int));

  printf("davor: \n");
  for (int i = 0; i < arr_size; i++)
  {
    printf("i: %d num: %d\n", i, arr[i]);
  }

  // count_sort(arr,arr_out,arr_size);
  count_sort_reverse(arr, arr_out, arr_size);

  printf("danach: \n");
  for (int i = 0; i < arr_size; i++)
  {
    printf("i: %d num: %d\n", i, arr_out[i]);
  }

  return 0;
}