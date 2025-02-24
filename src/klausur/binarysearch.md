# Binary Search

### Time complexity: O(log n)

Wir gehen davon aus, dass der Array sortiert ist.<br/>
Wir nehmen immer die Mitte des Arrays und gehen dann, entsprechend ob die Zahl größer oder kleiner ist, nach Links oder nach Rechts im Array (x ist größer (wir müssen nach rechts): low = middle + 1, x ist kleiner (wir müssen nach links): high = middle - 1)
<br/>

<code>

int binarysearch(int \*arr, int arr_size, int x)
{
int low = 0;
int high = arr_size - 1;
printf("suche nach: %d\n", x);

int try = 0;
// ausführen, solange high größer gleich low ist
while (low <= high)
{
int middle = low + (high - low) / 2;
int val = arr[middle]; // value at middle

    try++;
    printf("[%d] mittelwert: %d\n", try, val);

    // x ist größer als der mittelwert, also müssen wir weiter nach rechts
    if (x > val)
      low = middle + 1;
    else if (x < val)
      // nach links gehen, da x kleiner als der mittel wert ist
      high = middle - 1;
    else if (val == x)
      // wert gefunden #geilomatiko
      return middle;

}

return -1;
}
</code>
