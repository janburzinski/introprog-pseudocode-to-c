// gcc src/klausur/datenstrukturen/linked_and_double_linked_list.c -o builds/linked_and_double_linked_list.exe && ./builds/linked_and_double_linked_list.exe

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
  int value;
  struct Node *next;
} Node;

/**
 * Linked List
 */

void insert_into_array()
{
  Node *arr = (Node *)malloc(sizeof(Node));
  if (arr == NULL)
    return;

  arr->value = 1;
  arr->next = NULL;
}

void delete_from_array()
{
  // aufgabe: erstes element, letztes element und element an bestimmter position
}

void search_array()
{
  // aufgabe: nach zahl in array suchen
}

void reverse_array()
{
  // aufgabe: gesamte liste umkehren, nur bis zur mitte umkehren
}

void combine_two_arrays()
{
  // aufgabe: zwei arrays zusammenführen
}

/**
 * Double Linked List
 */

typedef struct
{
  int value;
  struct DoubleNode *previos;
  struct DoubleNode *next;
} DoubleNode;

void print_from_back_double_array()
{
  // aufgabe: elemente von hinten ausgeben
}

void insert_into_double_array()
{
  // aufgabe: neues element am anfang, am ende, an bestimmte position
}

void delete_from_double_array()
{
  // aufgabe: erstes element, letztes element und element an bestimmter position
}

void search_double_array()
{
  // aufgabe: nach zahl in array suchen
}

void reverse_double_array()
{
  // aufgabe: gesamte liste umkehren, nur bis zur mitte umkehren
}

void combine_two_double_arrays()
{
  // aufgabe: zwei arrays zusammenführen
}

int main()
{
  int arr[] = {4, 3, 2, 1, 533, 53};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  insert_into_array();
  delete_from_array();
  search_array();
  reverse_array();
  combine_two_arrays();

  print_from_back_double_array();
  insert_into_double_array();
  delete_from_array();
  search_double_array();
  reverse_double_array();
  combine_two_double_arrays();

  return 0;
}