#include <stdio.h>

int ret_value()
{
  int a = 35;
  int b = 42;

  printf("--- inde i ret_value ---\n");
  printf("Value of   a: %d\n", a);
  printf("Address of a: %d\n", &a);
  printf("Value of   b: %d\n", b);
  printf("Address of b: %d\n", &b);

  return a;
}

int main()
{
  int a = 1234;
  int b = 5678;
  
  printf("--- før beregning ---\n");
  printf("Value of   a: %d\n", a);
  printf("Address of a: %d\n", &a);
  printf("Value of   b: %d\n", b);
  printf("Address of b: %d\n", &b);

  a = b + 2;

  printf("--- før ret_value ---\n");
  printf("Value of   a: %d\n", a);
  printf("Address of a: %d\n", &a);
  printf("Value of   b: %d\n", b);
  printf("Address of b: %d\n", &b);

  a = ret_value();

  printf("--- efter ret_value ---\n");
  printf("Value of   a: %d\n", a);
  printf("Address of a: %d\n", &a);
  printf("Value of   b: %d\n", b);
  printf("Address of b: %d\n", &b);

  return 0;
}