#include "alg-practice-util.h"

bool is_sorted(int *arr, int arr_size)
{
    for (int i = 1; i < arr_size; i++)
    {
        if (arr[i] < arr[i - 1])
            return true;
    }
    return false;
}

void print_array(int *arr, int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        printf("[%d] >> %d\n", i, arr[i]);
    }
    printf("\n");
}

void test_arr(void (*sorting_func)(int *, int), int *arr, int arr_size, const char *alg_name)
{
    printf("davor: \n");
    print_array(arr, arr_size);

    sorting_func(arr, arr_size);

    printf("danach: \n");
    print_array(arr, arr_size);

    if (is_sorted(arr, arr_size) == 0)
    {
        printf("[%s] :))))) Array ist erfolgreich sortiert!\n", alg_name);
    }
    else
    {
        printf("[%s] ;((((( Array ist nicht erfolgreich sortiert!\n", alg_name);
    }
}

void swap(int *arr, int pos, int pos_2)
{
    int temp = arr[pos];
    arr[pos] = arr[pos2];
    arr[pos2] = temp;
}