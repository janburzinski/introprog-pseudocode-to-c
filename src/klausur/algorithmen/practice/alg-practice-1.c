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

void build_max_heap(int *arr, int arr_size)
{
  for (int i = (arr_size / 2 - 1); i >= 0; i--)
  {
    heapify(arr, arr_size, i);
  }
}

void heapify(int *arr, int arr_size, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left <= arr_size && arr[left] > arr[largest])
    largest = left;

  if (right <= arr_size && arr[right] > arr[largest])
    largest = right;

  if (largest != i)
  {
    swap(arr, i, largest);
    heapify(arr, arr_size, largest);
  }
}

void heapsort(int *arr, int arr_size)
{
  build_max_heap(arr, arr_size);
  for (int i = arr_size - 1; i > 0; i--)
  {
    // letztes element mit dem parent element tauschen
    swap(arr, 0, i);
    // heap eigenschaft wiederherstellen
    heapify(arr, i, 0);
  }
}

int partition_qs(int *arr, int start, int end)
{
  int pivot = arr[end];
  int i = start - 1; // i wird verwendet, um das kleinste Element zu tracken und dann später mit j zu tauschen

  // wir gehen vom start bis zum vor letzten element (das letzte element ist ja schon das pivot)
  for (int j = start; j <= end - 1; j++)
  {
    // ist das pivot element größer als das element an position j?
    // wenn ja, dann tauschen wir das element an position j mit dem element an position i
    // wir müssen auch mit i ein Feld weiter gehen, da wir nun i mit j tauschen
    // i ist das kleinere Element und unser Ziel ist es, alle Elemente auf der linken Seite kleiner als das Pivot Element zu haben
    if (arr[j] < pivot)
    {
      i++;
      swap(arr, i, j);
    }
  }
  // wir sind fertig und müssen jetzt nur noch das pivot element richtig setzen und zurückgeben
  i++;
  // wir verwendet hierbei als zweites Element end, da int pivot, ja die Zahl an pos[end] enthält und nicht den index
  swap(arr, i, end); // wir tauschen hierbei das element i mit dem pivot und setzen den pivot somit richtig

  return i; // i ist the position unseres pivots
}

// für do_quicksort: start = 0; end = arr_size
void quicksort(int *arr, int start, int end)
{
  if (end <= start)
    return; // base case: der array ist fertig sortiert

  int pivot = partition_qs(arr, start, end);
  // wir wählen hierbei start als start element, da wir vom ersten element an gehen wollen
  // wir wählen hier pivot - 1 als end element, da wir nur die linke Seite, also die seite mit den kleineren Elementen, uns angucken wollen
  quicksort(arr, start, pivot - 1); // linke Seite

  // wir wählen hier als start element pivot + 1, da wir uns nur die Elemente der rechten Seite uns angucken wollen, die Seite mit den größeren Elementen
  // wir wählen hier ganz normal das end element da wir bis zum ende des arrays gehen wollen
  quicksort(arr, pivot + 1, end); // rechte seite
}

void do_quicksort()
{
  //
  // ADD DO QUICKSORT METHOD HERE
  //
}

void insertion_sort(int *arr, int arr_size)
{
  // erstes element wird berets als sortiert betrachtet
  // wir gehen also vom ersten element bis zum letzten
  for (int i = 1; i < arr_size; i++)
  {
    int temp = arr[i];
    int j = i - 1; // links vergleich
    // wir vergleichen das element links von temp mit temp und tauschen falls größer
    // das element bei i mit dem linken element und dekrementieren dann j und 1
    while (j >= 0 && arr[j] > temp)
    {
      arr[j + 1] = arr[j]; // wir tauschen das element bei i (j+1) mit dem element links davon (j)
      j = j - 1;           // da i++ gemacht wird, müssen wir bei j wieder ein abziehen, um immer mit dem linken element zu vergleichen
    }
    arr[j + 1] = temp;
  }
}

void countsort(int *arr, int *arr_out, int arr_size)
{
  printf("miau\n");
  int max = arr[0];
  for (int i = 1; i < arr_size; i++)
  {
    if (arr[i] > max)
      max = arr[i];
  }
  printf("countsort beginnt %d\n", max);

  int *count = (int *)calloc((max + 1), sizeof(int));
  if (count == NULL)
    return;

  // zahlen zählen
  for (int i = 0; i < arr_size; i++)
  {
    count[arr[i]]++;
  }

  // array rekonstruieren
  int arr_idx = 0;
  for (int k = 0; k <= max; k++)
  {
    printf("[%d] %d\n", k, count[k]);
    while (count[k] > 0)
    {
      arr_out[arr_idx++] = k;
      count[k]--;
    }
  }

  free(count);
}

void test_countsort()
{
  printf("countsort:\n");
  int arr1[] = {64, 64, 11, 34, 25, 12, 22, 11, 90};
  int arr1_size = sizeof(arr1) / sizeof(arr1[0]);
  int *arr1_out = (int *)malloc(arr1_size * sizeof(int));

  printf("davor: \n");
  for (int i = 0; i < arr1_size; i++)
  {
    printf("[%d] %d\n", i, arr1[i]);
  }
  printf("\n");

  countsort(arr1, arr1_out, arr1_size);

  printf("danach: \n");
  for (int i = 0; i < arr1_size; i++)
  {
    printf("[%d] %d\n", i, arr1_out[i]);
  }
  printf("\n");
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
  test_arr(selection_sort, arr2, arr2_size, "selection_sort");
  test_arr(selection_sort, arr3, arr3_size, "selection_sort");
  test_arr(selection_sort, arr4, arr4_size, "selection_sort");
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
  test_heap_sort();
  test_insertion_sort();
  test_countsort();

  return 0;
}