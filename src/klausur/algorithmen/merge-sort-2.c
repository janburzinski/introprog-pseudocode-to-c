// gcc src/klausur/algorithmen/merge-sort-2.c -o builds/merge-sort-2.exe && ./builds/merge-sort-2.exe
#include <stdio.h>
#include <stdlib.h>

// merge fügt die zwei teilarrays wieder zu einem sortierten array zusammen
void merge(int *arr, int left_idx, int middle_idx, int right_idx)
{
  int size = right_idx - left_idx + 1; // gesamtgröße der zusammenzufügden arrays
  int *helper_arr = malloc(size * sizeof(int));
  int helper_idx = 0; // zeiger für helper arr

  int left_ptr = left_idx;        // zeiger auf das erste element im der linken hälfte
  int right_ptr = middle_idx + 1; // zeuger auf das erste element in der rechten hälfte

  // beide teilarrays durchlaufen und kleinere elemente in helper arr speichern
  // dies machen wir solange, bis wir entweder bei der mitte oder dem rechtesten element sind
  while (left_ptr <= middle_idx && right_ptr <= right_idx)
  {
    // ist das linke element kleiner gleich dem rechten Element,
    // dann fügen wir es zum helper_arr hinzu und schieben den helper_idx und left_ptr weiter
    if (arr[left_ptr] <= arr[right_ptr])
    {
      helper_arr[helper_idx] = arr[left_ptr];
      helper_idx++;
      left_ptr++;
    }
    else
    {
      // ist das rechte element kleiner gleich dem linken element, dann fügen wir zum helper_arr hinzu
      // und schieben den helper_idx und right_idx weiter
      helper_arr[helper_idx] = arr[right_ptr];
      helper_idx++;
      right_ptr++;
    }
  }

  // wir prüfen jetzt ob es noch übrig gebliebene elemente in der links oder rechten hälfte gibt
  // und sortieren diese richtig zu
  while (left_ptr <= middle_idx)
  {
    helper_arr[helper_idx] = arr[left_ptr];
    helper_idx++;
    left_ptr++;
  }

  while (right_ptr <= right_idx)
  {
    helper_arr[helper_idx] = arr[right_ptr];
    helper_idx++;
    right_ptr++;
  }

  // helper_arr in den normalen array wieder reinkopieren
  for (int k = 0; k < size; k++)
  {
    // wir setzen das element bei heler_arr[k] an die stelle von arr[left_idx + k]
    // left_idx und k sind beim ersten durchgang 0, wodurch das erste element ersetzt wird, und dies geht dann immer weiter so...
    // dadurch, dass k immer +1 geht, durchsuchen wir auch gleich den rechten array
    arr[left_idx + k] = helper_arr[k];
  }

  free(helper_arr);
}

// mergesort wird rekursiv verwendet, um die arrays in zwei hälften zui teilen und jede hälfte zu sortieren
void mergesort(int *arr, int left_idx, int right_idx)
{
  // linke idx kleiner als rechter:
  // nur noch 1 element ist übrig und wir haben den array fertig sortiert
  if (left_idx < right_idx)
  {
    int middle_idx = (left_idx + right_idx) / 2; // mitte des arrays finden

    mergesort(arr, left_idx, middle_idx);        // linke hälfte sortieren
    mergesort(arr, middle_idx + 1, right_idx);   // rechte hälfte sortieren
    merge(arr, left_idx, middle_idx, right_idx); // beide array hälften wieder zusammenfügen
  }
}

void print_array(int *arr, int arr_size)
{
  for (int i = 0; i < arr_size; i++)
    printf("[%d] %d\n", i, arr[i]);
  printf("\n");
}

int main()
{
  int arr[] = {38, 27, 43, 3, 9, 82, 10};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("davor: \n");
  print_array(arr, arr_size);

  mergesort(arr, 0, arr_size - 1);

  printf("danach: \n");
  print_array(arr, arr_size);

  return 0;
}