// gcc src/klausur/algorithmen/practice/alg-practice-insertionsort.c src/klausur/algorithmen/practice/alg-practice-util.c -o builds/alg-practice-insertionsort.exe && ./builds/alg-practice-insertionsort.exe

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alg-practice-util.h"

/**
 *
 * time complexity:
 *  best case: O(n) -> while schleife wird nie durchlaufen, weil schon sortiert
 *  worst case: O(n^2) -> while schleife muss jedes element sortieren
 *  average case: O(n^2) _> while schleife muss jedes element sortieren
 *
 * Stabil: Ja
 *
 * vorgehensweise:
 * - das erste element halten wir erstmal für sortiert
 * - wir vergleich immer die elemente rechts von einander, gestartet bei idx = 1
 *    => wir würden also bei i = 1 anfange, und dann rückwerts vergleichen sozusagen.
 *    => temp = arr[i] -> element welches sortiert werden muss
 *    => pos_to_insert = i -> dies ist die aktuelle position von dem element, welcheswir einfügen wollen
 *
 */

void insertionsort(int *arr, int arr_size)
{
  for (int i = 1; i < arr_size; i++)
  {
    int temp = arr[i];     // element, welches es zu sortieren gilt
    int pos_to_insert = i; // aktuelle position von dem element, welches wir einfügen wollen
    // pos_to_insert größer 0, da wir sonst ja schon am anfang sind und sozusagen auch fertig
    // UND
    // wir vergleichen den wert links mit dem zwischengespeicherten element an pos i, und schauen ob links größer als rechts ist
    printf("pos_to_insert: %d, temp: %d, temp-1: %d\n", pos_to_insert, temp, arr[pos_to_insert - 1]);
    while (pos_to_insert > 0 && arr[pos_to_insert - 1] > temp)
    {
      arr[pos_to_insert] = arr[pos_to_insert - 1]; // das derzeitige element mit dem element links davon tauschen und somit die richtige reinfolge herzustellen
      pos_to_insert--;                             // wert dekrementieren um ihn weiter richtung anfang zu verschieben
    }
    // wir sind fertig, also temp / den wert zum sortieren, final einfügen
    arr[pos_to_insert] = temp;
  }
}

int main()
{
  int arr[] = {1, 5, 3, 2, 6, 123, 6, 4, 33};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  print_array(arr, arr_size);

  insertionsort(arr, arr_size);

  print_array(arr, arr_size);

  return 0;
}