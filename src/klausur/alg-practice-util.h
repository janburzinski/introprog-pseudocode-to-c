#ifndef ALG_PRACTICE_UTIL_H
#define ALG_PRACTICE_UTIL_H

#include <stdbool.h>
#include <stdio.h>

bool is_sorted(int *arr, int arr_size);
void print_array(int *arr, int arr_size);
void test_arr(void (*sorting_func)(int *, int), int *arr, int arr_size, const char *alg_name);

#endif