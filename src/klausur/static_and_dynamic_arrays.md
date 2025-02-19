# Static and Dynamic Arrays

Einen Dynamic Array kann man mithilfe von structs erstellen, z.B.:
<code>
typedef struct {
int \*array;
int length;
int capacity;
} DynamicArray;

DynamicArray \*arr = (DynamicArray _)malloc(sizeof(DynamicArray));
arr->length = 2;
arr->capacity = 2;
arr->array = (int \*)malloc(2 _ sizeof(int)); // die zahl 2 ist nur ein beispiel
...
</code>

Neues Element einfügen:
<code>
...
arr->length += 1;
arr->capacity += 1;
arr->array = (int \*)realloc(arr->capacity, sizeof(int));
arr->array[arr->length] = 5;
...
</code>

Element löschen:
<code>
...
int welche_zahl = 5;

for(int i = 0; i < arr->length; i++) {
if(arr->array[i] == welche_zahl) arr->array[i] = arr->array[i + 1];
}
arr->length -= 1;
arr->capacity -= 1;
arr->array = (int \*)realloc(arr->capacity, sizeof(int));
...
</code>
