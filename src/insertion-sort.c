#include <stdio.h>

int main() {
  int arr[] = {8,15,3,14,7,6,18,19};
  int arr_size = sizeof(arr) / sizeof(arr[0]);

  printf("davor: ");
  for (int i = 0; i < arr_size; i++) {
    printf("i: %d num: %d\n", i, arr[i]);
  }

  for (int j = 1; j < arr_size; j++) {
    int key = arr[j];
    int i = j - 1;
    while (i > 0 && arr[i]>key) {
      arr[i+1] = arr[i];
      i--; // i = i - 1
    }
    arr[i+1] = key;
  }

  printf("danach: ");
  for (int i = 0; i < arr_size; i++) {
    printf("i: %d num: %d\n", i, arr[i]);
  }

  return 0;
}
