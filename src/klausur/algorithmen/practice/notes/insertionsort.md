# Insertion Sort Notes

- Skip first Element
- Always compore current Element and the Element to the left of it and

- Use one for Loop and a while Loop
  => for(int i = 1; i < arr_size - 1; i++) // - 1, da wir das letzte element selber einsetzen an die richtige position
  - int temp = arr[i]
  - int j = i - 1;
    => while(j > 0 && arr[j - 1] > temp)
