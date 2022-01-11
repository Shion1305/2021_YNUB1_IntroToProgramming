#include<stdio.h>
int
main ()
{
  char a, b;
  a = 'x';
  b = 'y';
  printf ("a = %c, b = %c\n", a, b);
  a = b - a;
  b = -a + b;
  a = a + b;
  printf ("a = %c, b = %c\n", a, b);
}
