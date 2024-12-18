#include <stdio.h>

char word[] = "cat";
//Loop 1
int a()
{
  int i = 0;
  while(word[i]) 
  {
    i++;
  }
  return i;
}
//Loop 2
int b()
{
  int i = 0;
  while(1)
  {
    if(word[i] == 0)
      break;
    i++;
  }
  return i;
}
//Loop 3
int c()
{
  int i = 0;
  while(1)
  {
    if(word[i] == 0)
      goto out;
    i++;
  }
out:
  return i;
}

int main()
{
    //Loop 1
    printf("Loop 1: %d\n", a());
    //Loop 2
    printf("Loop 2: %d\n", b());
    //Loop 3
    printf("Loop 3: %d\n", c());
    return 0;
}
