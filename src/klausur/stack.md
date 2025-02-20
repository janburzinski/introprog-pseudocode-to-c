# Stack

Last in, first out (Letztes Element was rein kommt, ist das erste was entfernt wird)

- Werte werden gespeichert, basierend auf der Reinfolge in welcher sie hinzugefügt wurden

<code>
typedef struct {<br/>
  int value;<br/>
  int top;<br/>
} Stack;
</code>

### Operationen

##### Push (Insert)

- Element an das Ende des Stacks hinzufügen

##### Pop (Delete)

- Letzte Element rauslöschen

### Beispiel

- Man kann das erste Element nicht bekommen, ohne alle davor kommenden Elemente zu löschen
