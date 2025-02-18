// gcc src/klausur/algorithmen/practice/alg-practice-3.c src/klausur/algorithmen/practice/alg-practice-util.c -o builds/alg-practice-3.exe && ./builds/alg-practice-3.exe

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alg-practice-util.h"

/**
 * Best-Case: Ω(n)
 * Worst-Case: O(n^2)
 * Average-Case: Θ(n^2)
 */
void bubble_sort(int *arr, int arr_size)
{
  // von hinten nach vorne
  for (int j = arr_size - 1; j > 0; j--)
  {
    // von vorne nach hinten
    for (int i = 0; i < j; i++)
    {
      // wenn element bei i größer als das nächste element, dann tauschen
      if (arr[i] > arr[i + 1])
        swap(arr, i, i + 1);
    }
  }
}

/**
 * Best-Case: Ω(n^2)
 * Worst-Case: O(n^2)
 * Average-Case: Θ(n^2)
 *
 * Immer O(n^2), da immer beide Loops durchlaufen werden müssen, um überhaupt zum ersten Swap kommen zu können
 */
void selection_sort(int *arr, int arr_size)
{
  // vom ersten element an gucken wir
  for (int j = 0; j < arr_size - 1; j++)
  {
    // wir verwenden diese variable um zu speichern, an welche stelle sich das kleinste element derzeit befindet
    int min = j;
    // vom ersten element + 1, also immer eins weiter als das erste element,
    for (int i = j + 1; i < arr_size; i++)
    {
      // ist das element bei i(j+1, also immer das nächste von j) kleiner als das zwischengespeicherte min Element
      if (arr[i] < arr[min])
        min = i;
    }
    swap(arr, min, j);
  }
}

/**
 * Best-Case: Ω(n^2)
 * Worst-Case: O(n^2)
 * Average-Case: Θ(n^2)
 */
void insertion_sort(int *arr, int arr_size)
{
  // wir überspringen das erste element, und nehmen es als schon sortiert
  for (int i = 1; i < arr_size; i++)
  {
    int temp = arr[i];
    int j = i - 1;
    // wir vergleichen das linke element (j -> i - 1) mit dem derzeitigen element (temp -> arr[i])
    while (j >= 0 && arr[j] > temp)
    {
      // wir tauschen das element an pos i (j + 1 = i) mit dem linken element
      arr[j + 1] = arr[j];
      // j um 1 dekremieren, da wir
      j--;
    }
    arr[j + 1] = temp;
  }
}

void build_max_heap(int *arr, int arr_size)
{
  for (int i = (2 / arr_size - 1); i >= 0; i--)
    heapify(arr, arr_size, i);
}

void heapify(int *arr, int arr_size, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left <= arr_size && arr[left] > arr[largest])
    largest = left;
  if (right <= arr_size && arr[right] > arr[left])
    largest = right;

  if (largest != i)
  {
    swap(arr, i, largest);
    heapify(arr, arr_size, i);
  }
}

void heapsort(int *arr, int arr_size)
{
  build_max_heap(arr, arr_size);

  for (int i = arr_size - 1; i > 0; i--)
  {
    swap(arr, 0, i);
    heapify(arr, arr_size, i);
  }
}

int partition(int *arr, int start, int end)
{
  int pivot = arr[end];
  int i = start - 1;

  for (int j = start; j <= end - 1; j++)
  {
    if (arr[j] < pivot)
    {
      // mit dem kleinsten element eins weiter gehen
      i++;
      // daraufhin tauschen wir das kleinste element mit der position bei i
      swap(arr, i, j);
    }
  }
  // mit dem kleinsten element eins weiter gehen
  i++;
  // und das pivot in die richtige position bringen
  swap(arr, i, end);

  return i; // neues pivot zurückgeben
}

void quicksort(int *arr, int start, int end)
{
  if (start <= end)
    return;

  int pivot = partition(arr, start, end);
  quicksort(arr, start, pivot - 1);
  quicksort(arr, pivot + 1, end);
}

void test_selection_sort()
{
  int arr1[] = {64, 34, 25, 12, 22, 11, 90};
  int arr1_size = sizeof(arr1) / sizeof(arr1[0]);

  int arr2[] = {1, 1, 1, 1, 1};
  int arr2_size = sizeof(arr2) / sizeof(arr2[0]);

  int arr3[] = {-5, -10, 0, 5, 10};
  int arr3_size = sizeof(arr3) / sizeof(arr3[0]);

  int arr4[] = {100, 50, 25, 12, 6, 3, 1};
  int arr4_size = sizeof(arr4) / sizeof(arr4[0]);

  test_arr(selection_sort, arr1, arr1_size, "selection_sort");
}

void test_bubble_sort()
{

  printf("---------- BUBBLE SORT ----------");
  int arr1[] = {5, 3, 8, 4, 2};
  int arr1_size = sizeof(arr1) / sizeof(arr1[0]);

  int arr2[] = {1, 2, 3, 4, 5};
  int arr2_size = sizeof(arr2) / sizeof(arr2[0]);

  int arr3[] = {5, 4, 3, 2, 1};
  int arr3_size = sizeof(arr3) / sizeof(arr3[0]);

  int arr4[] = {10};
  int arr4_size = sizeof(arr4) / sizeof(arr4[0]);

  int arr5[] = {-3, -1, -4, -2, -5};
  int arr5_size = sizeof(arr5) / sizeof(arr5[0]);

  test_arr(bubble_sort, arr1, arr1_size, "bubble_sort");
  test_arr(bubble_sort, arr2, arr2_size, "bubble_sort");
  test_arr(bubble_sort, arr3, arr3_size, "bubble_sort");
  test_arr(bubble_sort, arr4, arr4_size, "bubble_sort");
  test_arr(bubble_sort, arr5, arr5_size, "bubble_sort");
  printf("---------- BUBBLE SORT ENDE ----------");
}

void test_insertion_sort()
{
  int arr1[] = {64, 34, 25, 12, 22, 11, 90};
  int arr1_size = sizeof(arr1) / sizeof(arr1[0]);

  int arr2[] = {1, 1, 1, 1, 1};
  int arr2_size = sizeof(arr2) / sizeof(arr2[0]);

  int arr3[] = {-5, -10, 0, 5, 10};
  int arr3_size = sizeof(arr3) / sizeof(arr3[0]);

  int arr4[] = {100, 50, 25, 12, 6, 3, 1};
  int arr4_size = sizeof(arr4) / sizeof(arr4[0]);

  int arr5[] = {3, 2, 1, 0, -1, -2, -3};
  int arr5_size = sizeof(arr5) / sizeof(arr5[0]);

  int arr6[] = {10};
  int arr6_size = sizeof(arr6) / sizeof(arr6[0]);

  test_arr(insertion_sort, arr1, arr1_size, "insertion_sort");
  test_arr(insertion_sort, arr2, arr2_size, "insertion_sort");
  test_arr(insertion_sort, arr3, arr3_size, "insertion_sort");
  test_arr(insertion_sort, arr4, arr4_size, "insertion_sort");
  test_arr(insertion_sort, arr5, arr5_size, "insertion_sort");
  test_arr(insertion_sort, arr6, arr6_size, "insertion_sort");
}

int main()
{
  test_bubble_sort();
  test_selection_sort();
  test_insertion_sort();

  return 0;
}