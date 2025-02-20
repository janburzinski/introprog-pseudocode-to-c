# Linked List und Double Linked List

### Linked List

=> Enthält einen derzeitigen Wert und einen Pointer auf den nächsten Wert in der Liste

- Einfügen: Anfang: O(1); Sonst: O(n)
- Löschen:
- Suchen:
- Access:

<code>
typedef struct {<br/>
  int value;<br/>
  struct Node *next;<br/>
} Node;
</code>

# Double Linked List

- Einfügen:
- Löschen:
- Suchen:
- Access:

<code>

typedef struct {
int value;
struct Node *previos;
struct Node *next;
} DoublyNode;
</code>
