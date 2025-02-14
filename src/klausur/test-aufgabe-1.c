// gcc src/klausur/test-aufgabe-1.c -o builds/test-aufgabe-1.exe && ./builds/test-aufgabe-1.exe
#include <stdio.h>
#include <stdlib.h>

/**
 * Die Aufgabe ist aus dem WhatsApp Chat von so einem Typen der anscheinend Tutor ist oder so keine Ahnung aber ich vertrau ihm
 *
 * Eine Programmieraufgabe könnte sowas sein wie:
 * "Schreib eine Funktion, der ein Array aus Integern und die Länge übergeben wird.
 * Die Funktion soll das Produkt aus dem größten Wert im Array und dem kleinsten Wert zurückgeben.
 * Falls größter und kleinster Wert gleich sind soll -1 zurückgegeben werden.".
 *
 */

int smallest_biggest(int *arr, int arr_size)
{
    int highest_num = arr[0];
    int lowest_num = arr[0];

    for (int i = 0; i < arr_size; i++)
    {
        printf("%d\n", arr[i]);
        if (arr[i] >= highest_num)
            highest_num = arr[i];
        if (arr[i] <= lowest_num)
            lowest_num = arr[i];
    }

    printf("high: %d low: %d\n", highest_num, lowest_num);

    if (highest_num == lowest_num)
        return -1;

    return highest_num * lowest_num;
}

int main()
{
    int test1[] = {1, 2, 3, 4, 5}; // Erwartet: 1 * 5 = 5
    int test1_size = sizeof(test1) / sizeof(test1[0]);

    int test3[] = {7, 7, 7, 7, 7}; // Erwartet: -1 (größter und kleinster Wert gleich)
    int test3_size = sizeof(test3) / sizeof(test3[0]);

    int test4[] = {100, 50, 25, 10, 5, 1}; // Erwartet: 1 * 100 = 100
    int test4_size = sizeof(test4) / sizeof(test4[0]);

    int test5[] = {0, 0, 0, 0, 0}; // Erwartet: -1 (größter und kleinster Wert gleich)
    int test5_size = sizeof(test5) / sizeof(test5[0]);

    int test7[] = {42}; // Erwartet: -1 (nur ein Element, daher max == min)
    int test7_size = sizeof(test7) / sizeof(test7[0]);

    int test8[] = {-1, 2, -3, 4, -5}; // Erwartet: -5 * 4 = -20
    int test8_size = sizeof(test8) / sizeof(test8[0]);

    // test execution

    int test1_res = smallest_biggest(test1, test1_size);
    if (test1_res != 5)
    {
        printf("test 1 failed: %d\n", test1_res);
        return 1;
    }

    int test3_res = smallest_biggest(test3, test3_size);
    if (smallest_biggest(test3, test3_size) != -1)
    {
        printf("test 3 failed: %d\n", test1_res);
        return 1;
    }

    int test4_res = smallest_biggest(test4, test4_size);
    if (smallest_biggest(test4, test4_size) != 100)
    {
        printf("test 4 failed: %d\n", test1_res);
        return 1;
    }

    int test5_res = smallest_biggest(test5, test5_size);
    if (smallest_biggest(test5, test5_size) != -1)
    {
        printf("test 5 failed: %d\n", test1_res);
        return 1;
    }

    int test7_res = smallest_biggest(test7, test7_size);
    if (smallest_biggest(test7, test7_size) != -1)
    {
        printf("test 7 failed: %d\n", test1_res);
        return 1;
    }

    int test8_res = smallest_biggest(test8, test8_size);
    if (smallest_biggest(test8, test8_size) != -20)
    {
        printf("test 8 failed: %d\n", test1_res);
        return 1;
    }

    printf("all tests passed");

    return 0;
}