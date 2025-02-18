// gcc src/klausur/algorithmen/practice/alg-practice-2.c src/klausur/algorithmen/practice/alg-practice-util.c -o builds/alg-practice-2.exe && ./builds/alg-practice-2.exe

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alg-practice-util.h"

void bubble_sort(int *arr, int arr_size)
{
    // von hinten nach vorne gehen
    for (int j = arr_size - 1; j > 0; j--)
    {
        // von vorne nach hinten
        for (int i = 0; i < j; i++)
        {
            swap(arr, i, i + 1);
        }
    }
}

void selection_sort(int *arr, int arr_size)
{
    for (int j = 0; j < arr_size - 1; j++)
    {
        int min = j;
        for (int i = j + 1; j < arr_size; i++)
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
    // heap eigenschaft herstellen mit der heapify funktion
    for (int i = (arr_size / 2 - 1); i >= 0; i--)
    {
        heapify(arr, arr_size, i);
    }
}

void heapify(int *arr, int arr_size, int i)
{
    int largest = i;
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;

    if (left_child <= arr_size && arr[left_child] > arr[largest])
        largest = left_child;

    if (right_child <= arr_size && arr[right_child] > arr[largest])
        largest = right_child;

    // nur tauschen, wenn wir eine größere zahl haben und es nicht die gleiche zahl ist die wir bereits haben
    if (largest != i)
    {
        swap(arr, i, largest);     // letztes größtes mit dem neuen großen element tauschen
        heapify(arr, arr_size, i); // heap eigenschaft rekursiv wiederherstellen
    }
}

void heapsort(int *arr, int arr_size)
{
    build_max_heap(arr, arr_size);
    for (int i = arr_size - 1; i > 0; i--)
    {
        swap(arr, 0, i);
        heapify(arr, i, 0);
    }
}

int partition(int *arr, int start, int end)
{
    int pivot = arr[end];
    int i = start - 1;

    // wir gehen vom start bis zum Ende - 1, da das letzte Element ja unser gewählter Pivot ist
    for (int j = start; j <= end - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    i++;
    swap(arr, i, end);

    return i;
}

void quicksort(int *arr, int start, int end)
{
    if (start <= end)
        return; // base case

    int pivot = partition(arr, start, end);
    quicksort(arr, start, pivot - 1); // links
    quicksort(arr, pivot + 1, end);   // rechts
}

int main()
{

    return 0;
}