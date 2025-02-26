// gcc src/klausur/aufgabe_aus_altklausur/a-01.c -o builds/a-01.exe && ./builds/a-01.exe

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_fib(int n)
{
  if (n <= 0)
  {
    return true;
  }
  else if (n == 1)
  {
    return true;
  }
  else
  {
    return is_fib(n - 1) + is_fib(n - 2);
  }
}

/**
Gegeben sei eine Funktion mit Signatur

bool is_fib(int x)

welche true zurückgibt, wenn eine Eingabe-Ganzzahl x eine Fibonacci-Zahl ist, sonst false. Sie müssen diese Funktion nicht implementieren, aber Sie dürfen sie aufrufen.

Schreiben Sie eine Funktion in C, welche die Anzahl aller Fibonaccizahlen kleiner oder gleich dem int n zurückgibt.
Alle Fibonaccizahlen sind größer oder gleich 0.
Sie können Integer-Überläufe ignorieren.
<stdbool.h> steht Ihnen zur Verfügung (d.h. Sie können bool verwenden).

Außerdem dürfen Sie – falls gewünscht – eine Implementierung von is_fib angeben, aber das ist nicht zwingend erforderlich.
 */

int main()
{
  int c = 0;
  int n = 12;

  for (int i = 0; i <= n; i++)
  {
    if (is_fib(i))
      c += 1;
  }

  printf("%d hat %d fib zahlen #geilo\n", n, c);

  return 0;
}