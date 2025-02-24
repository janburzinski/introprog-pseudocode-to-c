# Queue

##### Beispiel: Warteschlange (z.B. in einem Laden)

First in, first out (Erstes Element was rein geht, ist das erste was gelöscht wird)

- Kann nicht Out of Bounds gehen. Falls man über das letzte Element drüber gehen würde, würde man einfach zurück an den Anfang gehen

<code>
typedef struct {<br/>
  int value;<br/>
  int front, back;<br/>
} Queue;
</code>

### Operationen

##### Enqueue (Insert)

Time complexity: O(1)

- Einfügen von Elementen an das Ende der Queue

##### Dequeue (Delete)

Time complexity: O(1)

- Entfernt das erste Item in der Queue

#### Contains/Removal

Time complexity: O(n)
