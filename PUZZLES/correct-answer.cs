// gcc ImpredictivePropositionalLogic1.c -o ImpredictivePropositionalLogic1.exe -std=c99 -Wall -O3

/*
Which answer in this list is the correct answer to this question?

(a) All of the below.
(b) None of the below.
(c) All of the above.
(d) One of the above.
(e) None of the above.
(f) None of the above.
*/

#include <stdio.h>
#define iff(x, y) ((x)==(y))

int main() {
  printf("a b c d e f\n");
  for (int a = 0; a <= 1; a++)
  for (int b = 0; b <= 1; b++)
  for (int c = 0; c <= 1; c++)
  for (int d = 0; d <= 1; d++)
  for (int e = 0; e <= 1; e++)
  for (int f = 0; f <= 1; f++) {
    int Ra = iff(a, b && c && d && e && f);
    int Rb = iff(b, !c && !d && !e && !f);
    int Rc = iff(c, a && b);
    int Rd = iff(d, (a && !b && !c) || (!a && b && !c) || (!a && !b && c));
    int Re = iff(e, !a && !b && !c && !d);
    int Rf = iff(f, !a && !b && !c && !d && !e);

    int R = Ra && Rb && Rc && Rd && Re && Rf;
    if (R) printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
  }
  return 0;
}
