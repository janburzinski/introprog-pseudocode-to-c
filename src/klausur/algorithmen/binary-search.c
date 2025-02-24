// gcc src/klausur/algorithmen/binary-search.c -o builds/binary-search.exe && ./builds/binary-search.exe

#include <stdio.h>
#include <stdlib.h>

/**
 *
 * wir suchen nach einer bestimmten zahl in einem sortierten array
 *
 * wir halbieren den array und schauen dann, ob die zahl größer oder kleiner ist. kleiner links, größer rechts
 *
 */

int binarysearch(int *arr, int arr_size, int x)
{
  int low = 0;
  int high = arr_size - 1;
  printf("suche nach: %d\n", x);

  int try = 0;
  // ausführen, solange high größer gleich low ist
  while (low <= high)
  {
    int middle = low + (high - low) / 2;
    int val = arr[middle]; // value at middle

    try++;
    printf("[%d] mittelwert: %d\n", try, val);

    // x ist größer als der mittelwert, also müssen wir weiter nach rechts
    if (x > val)
      low = middle + 1;
    else if (x < val)
      // nach links gehen, da x kleiner als der mittel wert ist
      high = middle - 1;
    else if (val == x)
      // wert gefunden #geilomatiko
      return middle;
  }

  return -1;
}

void print_array(int *arr, int arr_size)
{
  for (int i = 0; i < arr_size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main()
{
  int arr[] = {1,
               3,
               5,
               7,
               8,
               12,
               23,
               42,
               55,
               56,
               57};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  print_array(arr, arr_size);

  int x = 12;

  int f = binarysearch(arr, arr_size, x);

  if (f == -1)
    printf("wert ist nicht drin #nichtsogeilo");
  else
    printf("wert gefunden bei idx: %d", f);

  return 0;
}