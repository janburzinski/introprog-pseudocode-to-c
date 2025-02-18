// gcc src/klausur/algorithmen/count-sort.c -o builds/count-sort.exe && ./builds/count-sort.exe

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void count_sort(int *arr_in, int *arr_out, int arr_len)
{
  // größte vorkommende zahl ermitteln
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
      arr_out[idx++] = k;
      count[k]--;
    }
  }

  free(count);
}

int main()
{
  return 0;
}