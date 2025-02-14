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

int main()
{

    return 0;
}