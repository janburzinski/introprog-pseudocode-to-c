#include <stdio.h>

/**
 *
 * Insertion Sort:
 * Wir überspringen das erste Element und überprüfen dann einfach,
 * ob das Element an pos arr[i] größer als key ist (zwischengespeicherter wert von arr[j])
 * i ist hierbei immer das linke Element von arr[j] (j-1)
 *
 * Falls das Element bei arr[i] größer als key ist, dann tauschen wir es und dekrementieren i,
 * da wir immer nur das linke Element vergleichen wollen.
 *
 * Nach der while Loop setzen wir dann noch das Element key (arr[j]) an seine richtige Position
 *
 */

int main()
{
  int arr[] = {8, 15, 3, 14, 7, 6, 18, 19};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("davor: ");
  for (int i = 0; i < arr_size; i++)
  {
    printf("i: %d num: %d\n", i, arr[i]);
  }

  for (int j = 1; j < arr_size; j++)
  {
    int key = arr[j];
    int i = j - 1;
    while (i > 0 && arr[i] > key)
    {
      arr[i + 1] = arr[i];
      i--; // i = i - 1
    }
    arr[i + 1] = key;
  }

  printf("danach: ");
  for (int i = 0; i < arr_size; i++)
  {
    printf("i: %d num: %d\n", i, arr[i]);
  }

  return 0;
}
