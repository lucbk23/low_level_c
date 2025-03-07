#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void line(char* textpointer, char c, int repeat){
    textpointer[repeat +1] = '\0'; 

    while(repeat--){
        textpointer[repeat] = c; 
    }
    printf("Hello, world!\n%s\n", textpointer);
    printf("Size of str: %lu\n", strlen(textpointer)); 
    return; 
}

int main(){
    char *str = malloc(13 + 1);
      if (str != NULL) { 
    line(str,'=', 13);  
    printf("Hello, world!\n%s\n", str); 
    free(str); 
    }
    
    return 0;
    }




