#include <stdio.h>

void b_func(int b);

int main()
{
  char a = 47;
  char b = a;

  printf("Value of   a: %d\n", a);
  printf("Address of a: %d\n", &a);

  printf("Value of   b: %d\n", b);
  printf("Address of b: %d\n", &b);

	// her er plads til at kalde en funktion
    
    b_func(b);

    printf("Value of b: %d\n", b);
    printf("Address of b: %d\n", &b);
  return 0;
}

void b_func(int b)
{
printf(">>> inside b_func >>>\n");
printf("Value of   b: %d\n", b);
printf("Address of b: %d\n", &b);

b = 33;

printf("Value of   b: %d\n", b);
printf("Address of b: %d\n", &b);   
printf("<<< leaving b_func <<<\n");
}