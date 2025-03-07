#include <stdio.h>
int main() 
{
  long long x  = 0x7165498511230;
  long long x0 = 0xC894A7B75116601;
  long long x1 = 0;
  long long x2 = 0;
  long long x3 = 0;
  long long x4 = 0;
  long long x5 = 0;

  //while (x) putchar(32 + ((0xC894A7B75116601 >> ((x >>= 4) & 15) *7) & 0x7F));
  while (x) {
    printf("This is X: %0llx\n", x);
    x >>= 4;
    printf("This is new X: %0llx\n", x);
    x1 = x;
    printf("This is x1: %0llx\n", x1);
    x2 = x1 & 15;
    printf("This is x2: %0llx\n", x2);
    x3 = x2 * 7;
    printf("This is x3: %0llx\n", x3);
    x4 = x0 >> x3;
    printf("This is x4: %0llx\n", x4);
    x5 = x4 & 0x7F;
    printf("This is x5: %0llx\n", x5);
    putchar(32 + x5);

//putchar(32 + ((0xC894A7B75116601 >> ((x >>= 4) & 15) *7) & 0x7F));
  }
  return 0;

}