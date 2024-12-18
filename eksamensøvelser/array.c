#include <stdio.h>

int main()
{
  char letters[] = {'a', 'b', 'c', 'd', 'e', 'f'};

  for (int i = 0; i < 6; i++)
  {
    printf("Letter @ index %d is '%c'\n", i, i[letters]);
  }

  return 0;
}