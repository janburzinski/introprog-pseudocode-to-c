// gcc src/klausur/algorithmen/practice/alg-practice-1.c src/klausur/algorithmen/practice/alg-practice-util.c -o builds/alg-practice-1.exe && ./builds/alg-practice-1.exe

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alg-practice-util.h"

/**
 * (Äußere Loop) Wir starten beim letzten Element im Array und lassen die loop laufen bis zum ersten Element (j > 0) [ j-- => um immer weiter nach vorne zu gehen ]
 *    o	Die Loop läuft also genau bis arr_size – 1
 * => Loop verkleinert den Bereich in dem noch sortiert werden muss
 *    o	Das größte verbleibende Element ist nach jedem vollständigen Durchlauf dann an der richtigen Stelle.
 *
 * Eine zweite Loop (Innere Loop) läuft dann vom Anfang des Arrays bis zu j, bis sich die beiden Zahlen also treffen
 * => In dieser Loop vertauschen wir dann die Elemente und lassen sie nach unten „bubbeln“. Wir gucken also ob die Zahl an arr[i] größer ist als arr[i+1].
 *    o	Wenn die Zahl bei arr[i] also größer ist, dann tauschen wir die Zahlen und gehen weiter bis i < j.
 *
 */
void bubble_sort(int *arr, int arr_size)
{
  for (int j = arr_size - 1; j > 0; j--)
  {
    //
    for (int i = 0; i < j; i++)
    {
      if (arr[i] > arr[i + 1])
      {
        swap(arr, i, i + 1);
      }
    }
  }
}

void selection_sort(int *arr, int arr_size)
{
  for (int j = 0; j < arr_size - 1; j++)
  {
    int min = j;
    for (int i = j + 1; i < arr_size; i++)
    {
      if (arr[i] < arr[min])
      {
        min = i;
      }
    }
    swap(arr, min, j);
  }
}

void heapsort(int *arr, int arr_size)
{
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

void test_heap_sort()
{

  printf("---------- HEAP SORT ----------");
  int arr1[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
  int arr1_size = sizeof(arr1) / sizeof(arr1[0]);

  int arr2[] = {4, 10, 3, 5, 1};
  int arr2_size = sizeof(arr2) / sizeof(arr2[0]);

  int arr3[] = {1, 2, 3, 4, 5};
  int arr3_size = sizeof(arr3) / sizeof(arr3[0]);

  int arr4[] = {-1, -3, -2, -5, -4};
  int arr4_size = sizeof(arr4) / sizeof(arr4[0]);

  test_arr(heapsort, arr1, arr1_size, "heap_sort");
  test_arr(heapsort, arr2, arr2_size, "heap_sort");
  test_arr(heapsort, arr3, arr3_size, "heap_sort");
  test_arr(heapsort, arr4, arr4_size, "heap_sort");
  printf("----------  ENDE ----------");
}

int main()
{
  test_bubble_sort();
  test_selection_sort();
  test_heap_sort();

  return 0;
}