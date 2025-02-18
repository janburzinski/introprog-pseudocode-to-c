// gcc src/klausur/algorithmen/heap-sort.c -o builds/heap-sort.exe && ./builds/heap-sort.exe

#include <stdio.h>
#include <math.h>

/**
 *
 * heapsort (divide and conquer)
 * - das parent element wird immer als sortiert angesehen und der sortierte array wird sozusagen von hinten gebaut.
 * - wir nehmen immer das element von ganz hinten (das nächst größte zum Parent) und setzen es dann als Parent
 * - dies machen wir dann so lange bis wir den array komplett durch haben und der array gilt dann als sortiert
 *
 * -in der heapsort funktion gehen wir sicher, dass i immer um eins verringert wird, also nach jedem durchlauf die größe des arrays verringert wird
 * -mit build_max_heap bauen wir den eigentlich heap. dies ist die erste funktion die aufgerufen wird in void heapsort
 * -in meiner build max heap funktion bauen den max heap, indem wir von arr_size / 2 - 1 bis i = 0 gehen und dann die heapify(arr,arr_size,i) funktion aufrufen
 * -in der heapify funktion vergleichen wir das linke element (2*i+1) mit dem rechten element (2*i+2)
 * und schauen ob es größer als derzeitige größte Element ist (variable i, gespeichert in int largest direkt am anfang)
 *
 */

void swap(int *arr, int pos, int pos_2)
{
  int temp = arr[pos];
  arr[pos] = arr[pos_2];
  arr[pos_2] = temp;
}

/**
 *
 * Einen Max-Heap aus einem unsortierten Array erstellen
 *
 * Jedes Parent Element ist größer oder gleich sein Kind-Element
 */
void build_max_heap(int *arr, int arr_size)
{
  for (int i = arr_size / 2 - 1; i >= 0; i--)
    heapify(arr, arr_size, i);
}

/**
 *
 * Stellt die Heap Eigentschaft eines Teilbaumes sicher, indem Element bei idx: i mit seinem Kind verglichen wird
 * und ggf. tauscht
 *
 * Wird in 'build_max_heap' und 'heapsort' verwendet
 *
 * Voraussetzung: Teilbäume von i sind bereits Max-Heaps
 *
 * i => index des knotens der überprüft und korrigiert werden muss
 *
 */
void heapify(int *arr, int arr_size, int i)
{
  int largest = i;             // root of the tree
  int left_child = 2 * i + 1;  // left child
  int right_child = 2 * i + 2; // right child

  // left_child <= arr_size stellt sicher, dass ein linkes kind existiert
  // wenn ja, gucken wir auch noch, ob das left_child größer ist als das aktuell größte
  // wenn ja, dann ist das left_child das neue largest Element
  if (left_child < arr_size && arr[left_child] > arr[largest])
    largest = left_child;

  if (right_child < arr_size && arr[right_child] > arr[largest])
    largest = right_child;

  // wir stellen sicher, dass ein tausch nur gemacht wird,
  // wenn ein größeres element als das derzeit größte Element existiert (i = largest)
  if (largest != i)
  {
    // tausche das letzte größe Element mit dem neu gefundenen größten Element
    swap(arr, i, largest);
    // die heap eigenschaft wiederherstellen
    heapify(arr, arr_size, largest);
  }
}

/**
 *
 * 1. Max-Heap erstellen (build_max_heap)
 * 2. Größtes Element wird mit dem letzten Element (nächst größtes) getauscht und die größe des Arrays wird um 1 reduziert
 * 3. 'Heapify' wird auf die neue Wurzel angewendet, um die Heap Eigenschaft wiederherzustellen
 * 4. Prozess wird wiederholt, bis der Array sortiert ist.
 *
 */
void heapsort(int *arr, int arr_size)
{
  build_max_heap(arr, arr_size);

  for (int i = arr_size - 1; i > 0; i--)
  {
    // letztes element mit dem parent element tauschen
    swap(arr, 0, i);
    // heap bedingung wiederherstellen
    heapify(arr, i, 0);
  }
}

void print_array(int *arr, int arr_size)
{
  for (int i = 0; i < arr_size; i++)
    printf("%d: %d \n", i, arr[i]);
  printf("\n");
}

int main()
{
  int arr[] = {2, 8, 5, 3, 9, 1};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("davor: \n");
  print_array(arr, arr_size);

  heapsort(arr, arr_size);

  printf("danach: \n");
  print_array(arr, arr_size);

  return 0;
}