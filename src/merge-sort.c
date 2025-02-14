#include <stdio.h>
#include <stdlib.h>

void merge(int *nums, int left_idx, int middle_idx, int right_idx)
{
    int size = right_idx - left_idx + 1;
    int *helper_arr = malloc(size * sizeof(int));
    int i = left_idx;       // helper für die linke hälfte von nums
    int j = middle_idx + 1; // helper für die rechts hälfte von nums
    int b = 0;              // helper für den neuen array (helper_arr)

    while (i <= middle_idx && j <= right_idx)
    {
        if (nums[i] <= nums[j])
        {
            helper_arr[b] = nums[i];
            b++;
            i++;
        }
        else
        {
            helper_arr[b] = nums[j];
            b++;
            j++;
        }
    }

    while (i <= middle_idx)
    {
        helper_arr[b] = nums[i];
        b++;
        i++;
    }

    while (j <= right_idx)
    {
        helper_arr[b] = nums[j];
        b++;
        j++;
    }

    for (int k = 0; k < size; k++)
    {
        nums[left_idx + k] = helper_arr[k];
    }
    free(helper_arr);
}

void mergesort(int *nums, int left_idx, int right_idx)
{
    if (left_idx < right_idx)
    {
        int middle_idx = (left_idx + right_idx) / 2; // q: number on the middle of the array

        mergesort(nums, left_idx, middle_idx);        // linke hälfte sortieren
        mergesort(nums, middle_idx + 1, right_idx);   // rechte hälfte sortieren
        merge(nums, left_idx, middle_idx, right_idx); // beide arrays zusammenfügen
    }
}

int main()
{
    int nums[] = {4, 6, 7, 9, 12, 13, 15, 25};
    int arr_len = sizeof(nums) / sizeof(nums[0]);

    printf("davor: \n");
    for (int i = 0; i < arr_len; i++)
    {
        printf("i: %d num: %d\n", i, nums[i]);
    }

    mergesort(nums, 0, arr_len - 1);

    printf("danach: \n");
    for (int i = 0; i < arr_len; i++)
    {
        printf("i: %d num: %d\n", i, nums[i]);
    }

    return 0;
}