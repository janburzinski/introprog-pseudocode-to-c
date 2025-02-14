#include <stdio.h>

/**
 * there are two forms of selection sort
 * - one with a swap function
 * - one without
 *
 * Notizen:
 *
 * -
 */

void swap(int *arr, int min, int j)
{
  int h = arr[min];
  arr[min] = arr[j];
  arr[j] = h;
}

int main()
{
  int arr[] = {8, 15, 3, 14, 7, 6, 18, 19};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("davor: \n");
  for (int i = 0; i < arr_size; i++)
  {
    printf("i: %d num: %d\n", i, arr[i]);
  }

  //
  // selection sort without swap function
  //

  for (int j = 0; j < arr_size - 1; j++)
  {
    int min = j;
    for (int i = j + 1; i < arr_size; i++)
    {
      if (arr[i] < arr[min])
        min = i;
    }
    int h = arr[min];
    arr[min] = arr[j];
    arr[j] = h;
  }

  printf("danach: \n");
  for (int i = 0; i < arr_size; i++)
  {
    printf("i: %d num: %d\n", i, arr[i]);
  }

  //
  // selection sort with swap function
  //

  int arr2[] = {8, 15, 3, 14, 7, 6, 18, 19};

  printf("swap davor: \n");
  for (int i = 0; i < arr_size; i++)
  {
    printf("i: %d num: %d\n", i, arr2[i]);
  }

  for (int j = 0; j < arr_size - 1; j++)
  {
    int min = j;
    for (int i = j + 1; i < arr_size; i++)
    {
      if (arr2[i] < arr2[min])
        min = i;
    }
    swap(arr2, min, j);
  }

  printf("swap danach: \n");
  for (int i = 0; i < arr_size; i++)
  {
    printf("i: %d num: %d\n", i, arr2[i]);
  }

  return 0;
}