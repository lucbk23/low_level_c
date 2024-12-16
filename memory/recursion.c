#include <stdio.h>

void rec_func(int r);

int main()
{
  int a = 1234;
  int b = 5678;
  
	int r = 2;
  printf("--- before rec_func ---\n");
  rec_func(r);
  printf("--- after rec_func ---\n");
  
  return 0;
}

void rec_func(int r) 
{
  printf("--- inde i rec_func ---\n");

  printf("before - Value of   m: %d\n", r);
  printf("before - Address of m: %d\n", &r);

  if(r>0) 
  {
    rec_func(r-1);
  }
  
  printf("after - Value of   m: %d\n", r);
  printf("after - Address of m: %d\n", &r);

  printf("--- afslut rec_func ---\n");
}