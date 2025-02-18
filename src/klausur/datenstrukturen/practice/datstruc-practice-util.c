#include <datstruc-practice-util.h>

void print_array(int *arr, int arr_size)
{
  for (int i = 0; i < arr_size; i++)
    printf("[%d] >> %d\n", arr[i]);
  printf("\n");
}