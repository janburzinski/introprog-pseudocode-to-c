// gcc src/klausur/aufgabe_aus_altklausur/a-03.c -o builds/a-03.exe && ./builds/a-03.exe

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 *
 *  Ein Baum wird als Pointer auf ein Node dargestellt
 *
 */
typedef struct Node_
{
  int item;
  struct Node_ *left;
  struct Node_ *right;
} Node;

/**
 *
 *  Schreiben Sie eine Funktion in C, welche die Höhe eines Eingabebaums zurückgibt.
 * Zur Erinnerung: die Höhe des leeren Baums ist -1, die Höhe eines ein-elementigen Baums ist 0, etc.
 * Sie dürfen nur Funktionen aufrufen, für die Sie auch eine Implementierung aufschreiben.
 *
 */

int main()
{
  return 0;
}