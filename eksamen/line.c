#include <stdio.h>
#include <stdlib.h>

char * line(char c, int repeat){
    char *str = malloc(repeat + 1); // Allocate memory for the string plus null terminator
    if (str == NULL) { // Check if memory allocation was successful
        return NULL; // Return NULL if allocation failed
    }
    str[repeat] = '\0'; // Null terminator på strengen

    while(repeat--){
        str[repeat] = c; // Tildeler characteren 'c' til hver position i strengen
    }
    printf("Size of str: %lu\n", sizeof(*str));
    return str; // Returnerer pointer til den allokerede string
}

int main(){
    char *result = line('=', 13); // Opret en string med 13 '=' tegn
    if (result != NULL) { // Tjek om strengen blev oprettet korrekt og tjek om den er NULL, hvis den er ! null så fortsæt med at print
        printf("Hello, world!\n%s\n", result); // Brug strengen i printf
        free(result); // Frigør den allokerede hukommelse som jeg har kaldt result

        //printf("Hello, world!\n%s\n", line('=', 13)); // For god ordens skyld
    }

    return 0;
}

//Noter

//Originale problemer:
// At returnere en pointer til et lokalt stack-acllocated array er en fejl, da arrayet vil blive deallokeret når funktionen returnerer.
//Løst ved at bruge malloc og free til at frigøre memoryen til sidst og undgå så vidt muligt memory leaks

// Jeg har ændret str definationen til str *str så pointeren bliver valideret og den får fat i noget memory
//Jeg bruger malloc til at allokere memory til strengen
//Det er der IF statementet kommer ind, så den tjekker om strengen er == NULL, hvis den er, returnerer den NULL og stopper programmet
// I main har jeg tilføjet resultat func og oprettet en string med 13 == tegn til at vise jeg stopper programmet

