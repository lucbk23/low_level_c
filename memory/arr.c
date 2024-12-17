#include <stdio.h>

int main()
{
  char word[4] = {99, 97, 116, 0};
  char pet[4]; 
  //pet = word;
  word[0] = 100;
  word[1] = 111;
  word[2] = 103;

  printf("Value of   word: %d\n", word);
  printf("Address of word: %d\n", &word);
  printf("- word[0] value: %d\n", word[0]);
  printf("- word[0] addrs: %d\n", &word[0]);
  printf("- word[1] value: %d\n", word[1]);
  printf("- word[1] addrs: %d\n", &word[1]);
  printf("- word[2] value: %d\n", word[2]);
  printf("- word[2] addrs: %d\n", &word[2]);
  printf("- word[3] value: %d\n", word[3]);
  printf("- word[3] addrs: %d\n", &word[3]);


  printf("Value of   pet: %d\n", pet);
  printf("Address of pet: %d\n", &pet);
  printf("- pet[0] value: %d\n", pet[0]);
  printf("- pet[0] addrs: %d\n", &pet[0]);
  printf("- pet[1] value: %d\n", pet[1]);
  printf("- pet[1] addrs: %d\n", &pet[1]);
  printf("- pet[2] value: %d\n", pet[2]);
  printf("- pet[2] addrs: %d\n", &pet[2]);
  printf("- pet[3] value: %d\n", pet[3]);
  printf("- pet[3] addrs: %d\n", &pet[3]);
  return 0;
}