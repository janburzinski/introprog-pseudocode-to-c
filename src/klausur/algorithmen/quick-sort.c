// gcc src/klausur/algorithmen/quick-sort.c -o builds/quick-sort.exe && ./builds/quick-sort.exe

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int pos, int pos_2)
{
  int temp = arr[pos];
  arr[pos] = arr[pos_2];
  arr[pos_2] = temp;
}

/**
 *
 * Aufgabe: wir wollen, dass alle elemente links vom pivot element kleiner sind und alle elemente rechts vom pivot größer.
 *
 * Wir schaffen wir das?:
 * - wir haben int i = start - 1; und eine loop, int j, die vom anfang des arrays bis zum ende geht
 * - wir schauen, ob das element an pos j kleiner als das pivot ist
 *    - falls ja, dann i++
 *    - und wir tauschen das element an pos j mit dem element an pos i
 * - falls das element größer als das pivot element ist, dann tauschen wir das element an der pos j mit dem pivot
 *
 *
 * @return => idx an welchem sich das pivot element befindet
 */
int partition(int *arr, int start, int end)
{
  // wir setzen das pivot element einfach als das letzte element
  int pivot = arr[end];
  // i wird zum tausch mit j verwendet, wobei i dann immer das kleinere element ist
  //
  // i = start - 1, da wir nur die kleineren Elemente damit makieren wollen
  // und nicht das erste Element sozusagen überspringen, beim ersten tausch
  //
  // wir bewegen i nur, wenn wir ein element finden welcher kleiner als der pivot ist (j < pivot)
  int i = start - 1; // only needed to move, when we find an element that is smaller than the pivot (j < pivot)

  for (int j = start; j <= end - 1; j++)
  {
    if (arr[j] < pivot)
    {
      // mit der variable für die kleinste zahl eins weiter gehen
      i++;
      // dann die kleinste zahl (zahl an pos i) mit der derzeitigen Zahl tauschen
      swap(arr, i, j);
    }
  }
  // nach der loop setzen wir den pivot noch in seine finale position
  i++;
  swap(arr, i, end);

  return i;
}

void quicksort(int *arr, int start, int end)
{
  if (end <= start)
    return; // base case: we will not be able to further sort the array

  int pivot = partition(arr, start, end);
  quicksort(arr, start, pivot - 1); // left side of the array
  quicksort(arr, pivot + 1, end);   // right side of the array
}

void print_array(int *arr, int arr_size)
{
  for (int i = 0; i < arr_size; i++)
    printf("[%d] %d\n", i, arr[i]);
  printf("\n");
}

int main()
{
  int arr[] = {10, 7, 8, 9, 1, 5};      // Beispiel-Array
  int n = sizeof(arr) / sizeof(arr[0]); // Array-Länge berechnen

  printf("davor: \n");
  print_array(arr, n);

  quicksort(arr, 0, n - 1);

  printf("danach: \n");
  print_array(arr, n);

  return 0;
}