// gcc src/klausur/alg-practice-1.c src/klausur/alg-practice-util.c -o builds/alg-practice-1.exe && ./builds/alg-practice-1.exe

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "alg-practice-util.h"

/**
 * - wir starten von hinten und lassen die größeren zahlen langsam hoch "bubbeln"
 *
 * j => last element in the array
 * i => current element counting upwards from the last element
 */
void bubble_sort(int *arr, int arr_size)
{
    // - 1 because of out of bounds
    for (int j = arr_size - 1; j > 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
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
        int temp = arr[min];
        arr[min] = arr[j];
        arr[j] = temp;
    }
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

int main()
{
    test_bubble_sort();
    test_selection_sort();

    return 0;
}