#include<stdio.h>
int
main ()
{
  char a, b, work;
  a = 'x';
  b = 'y';
  printf ("a = %c, b = %c\n", a, b);
  work = a;
  a = b;
  b = work;
  printf ("a = %c, b = %c\n", a, b);
}