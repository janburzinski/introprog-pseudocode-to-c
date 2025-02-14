// gcc src/bubble-sort.c -o builds/bubble-sort.exe && ./builds/bubble-sort.exe
#include <stdio.h>

void swap(int *arr, int i, int i_n)
{
    int temp = arr[i];
    arr[i] = arr[i_n];
    arr[i_n] = temp;
}

void bubble_sort(int *arr, int arr_len)
{
    for (int j = arr_len - 1; j > 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (arr[i] > arr[i + 1])
                swap(arr, i, i + 1);
        }
    }
}

int main()
{

    int arr[] = {8, 15, 3, 14, 7, 6, 18, 19};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("davor: \n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("i: %d num: %d\n", i, arr[i]);
    }

    bubble_sort(arr, arr_size);

    printf("danach: \n");
    for (int i = 0; i < arr_size; i++)
    {
        printf("i: %d num: %d\n", i, arr[i]);
    }

    return 0;
}