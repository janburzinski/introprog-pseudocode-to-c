// gcc src/klausur/datenstrukturen/static_and_dynamic_array.c -o builds/static_and_dynamic_array.exe && ./builds/static_and_dynamic_array.exe

#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int arr_size);
void swap(int *arr, int pos, int pos_2);

/**
 * Statische Arrays
 */

// initialisierung und zugriff
void calc_avg()
{
  int arr[] = {1, 4, 5, 6, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  int sum = 0;

  for (int i = 0; i < arr_size; i++)
    sum += arr[i];

  int median = (sum / arr_size);
  printf("[avg] array: ");
  print_array(arr, arr_size);
  printf("avg: %d\n", median);
}

// suche
void search_and_return()
{
  int arr[] = {1, 4, 5, 6, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  int gefunden_idx = -1;
  int leckmeina = 5;

  for (int i = 0; i < arr_size; i++)
  {
    if (arr[i] == leckmeina)
      gefunden_idx = i;
  }

  printf("[search] array: ");
  print_array(arr, arr_size);
  printf("search: %d wo: %d\n", leckmeina, gefunden_idx);
}

// sortier algorithmus
void bubble_sort()
{
  int arr[] = {1, 8, 3, 6, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("[bubblesort] array davor: \n");
  print_array(arr, arr_size);

  for (int j = arr_size - 1; j > 0; j--)
  {
    for (int i = 0; i < j; i++)
    {
      if (arr[i] > arr[i + 1])
        swap(arr, i, i + 1);
    }
  }

  printf("[bubblesort] array danach: \n");
  print_array(arr, arr_size);
}

// array manipulation
void double_straight_nums()
{
  int arr[] = {1, 2, 8, 3, 4, 6, 7};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("[double straight nums] array davor: \n");
  print_array(arr, arr_size);

  int i = 0;

  // mal wat anderes als immer nur for loop
  while (i < arr_size)
  {
    if (arr[i] % 2 == 0)
      arr[i] = arr[i] * 2;
    i++;
  }

  printf("[double straight nums] array danach: \n");
  print_array(arr, arr_size);
}

/**
 * Dynamische Arrays
 */
typedef struct
{
  int *array;
  int length;
  int capacity;
} DynamicArray;

void allocate_and_insert()
{
  DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
  arr->length = 4;
  arr->capacity = 4;
  arr->array = (int *)malloc(arr->capacity * sizeof(int));

  int new_arr[] = {4, 5, 12, 45};
  for (int i = 0; i < arr->length; i++)
  {
    arr->array[i] = new_arr[i];
  }

  printf("[allocate-and-insert] array davor: \n");
  print_array(arr->array, arr->length);

  int n = 2;
  arr->capacity += 1;
  arr->length += 1;
  arr->array = (int *)realloc(arr->array, arr->capacity * sizeof(int)); // mehr speicher zuweisen, um die angepasste größe zu berücksichtigen
  arr->array[arr->length] = n;

  printf("[allocate-and-insert] array danach: \n");
  print_array(arr->array, arr->length);

  free(arr->array);
}

void allocate_and_delete()
{
  DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
  arr->capacity = 4;
  arr->length = 4;
  arr->array = (int *)malloc(arr->capacity * sizeof(int));

  int new_arr[] = {4, 5, 12, 45};
  for (int i = 0; i < arr->length; i++)
    arr->array[i] = new_arr[i];

  printf("[allocate-and-delete] array davor: \n");
  print_array(arr->array, arr->length);

  int welche_zahl = 12;
  for (int j = 0; j < arr->length; j++)
  {
    if (arr->array[j] == welche_zahl)
      // über das element einfach springen
      arr->array[j] = arr->array[j + 1];
  }
  arr->capacity -= 1;
  arr->length -= 1;

  printf("[allocate-and-delete] array danach: \n");
  print_array(arr->array, arr->length);

  free(arr->array);
}

void combine_two_arrays()
{
  // arrays zum späteren kombinieren
  int first_arr[] = {3, 1, 6, 3};
  int first_arr_size = sizeof(first_arr) / sizeof(first_arr[0]);

  int second_arr[] = {7, 3, 2, 74, 23};
  size_t second_arr_size = sizeof(second_arr) / sizeof(second_arr[0]);

  // leere dynmic array erstellen
  DynamicArray *arr = (DynamicArray *)malloc(sizeof(DynamicArray));
  arr->array = (int *)malloc(first_arr_size * sizeof(int));
  arr->capacity = first_arr_size;
  arr->length = first_arr_size;

  DynamicArray *arr_two = (DynamicArray *)malloc(sizeof(DynamicArray));
  arr_two->array = (int *)malloc(second_arr_size * sizeof(int));
  arr_two->capacity = second_arr_size;
  arr_two->length = second_arr_size;

  // arrays zu dynamic arrays hinzufügen
  for (int i = 0; i < first_arr_size; i++)
    arr->array[i] = first_arr[i];
  for (int j = 0; j < second_arr_size; j++)
    arr_two->array[j] = second_arr[j];

  // beide arrays kombinieren
  DynamicArray *combined_arr = (DynamicArray *)malloc(sizeof(DynamicArray));
  combined_arr->capacity = first_arr_size + second_arr_size;
  combined_arr->length = first_arr_size + second_arr_size;
  combined_arr->array = (int *)malloc(combined_arr->capacity * sizeof(int));

  // ersten array hinzufügen
  for (int k = 0; k < arr->length; k++)
    combined_arr->array[k] = arr->array[k];

  // zweiten array hinzufügen
  for (int l = 0; l < arr_two->length; l++)
    combined_arr->array[first_arr_size + l] = arr_two->array[l];

  printf("[combine two arrays] erster array: \n");
  print_array(first_arr, first_arr_size);

  printf("[combine two arrays] zweiter array: \n");
  print_array(second_arr, second_arr_size);

  printf("[combine two arrays] array zusammen: \n");
  print_array(combined_arr->array, combined_arr->length);

  free(arr);
  free(arr->array);
  free(arr_two);
  free(arr_two->array);
  free(combined_arr);
  free(combined_arr->array);
}

/**
 * Util
 */

void print_array(int *arr, int arr_size)
{
  for (int i = 0; i < arr_size; i++)
    printf("[%d] %d ", i, arr[i]);
  printf("\n");
}

void swap(int *arr, int pos, int pos_2)
{
  int temp = arr[pos];
  arr[pos] = arr[pos_2];
  arr[pos_2] = temp;
}

int main()
{
  // static
  calc_avg();
  search_and_return();
  bubble_sort();
  double_straight_nums();

  // dynamic
  allocate_and_insert();
  allocate_and_delete();
  combine_two_arrays();

  return 0;
}