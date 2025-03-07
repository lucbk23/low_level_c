#include <stdio.h>

int main() {

    //variabel deklarationer                        %s = string %x = hex %d = decimal %p = pointer
    int x = 195253924;
    //char v4 = '\0'; //null terminator
    char v3 = 'g';
    char v2 = 'o';
    char v1 = 'd';

    printf("v1: '%c' (0x%x) @ %p\n", v1, v1, &v1); //udskriver d + dens hex værdi som er 0x64
    printf("v2: '%c' (0x%x) @ %p\n", v2, v2, &v2); //udskriver o + dens hex værdi som er 0x6f
    printf("v3: '%c' (0x%x) @ %p\n", v3, v3, &v3); //udskriver g + dens hex værdi som er 0x67
    //printf("v4: '%c' (0x%x) @ %p\n", v4, v4, &v4); //udskriver null terminator + dens hex værdi som er 0x0 udkommenteret kan den føre til udefineret adfærd
    
    //den fortsætter med at læse hukommelse til den støder på en null terminator
    
    printf("Hele strengen: %s\n", &v1);
    printf("x: %d (adresse: %p)\n", x, &x); //udskriver 195253924 + dens adresse i hukommelsen

    return 0;
}

//2 den har læst hele adressen som er stored ved &v1 og fordi de er deklareret sekventielt så kan den fortsætte med at læse de andre variabler
//Udkommenteringen påvirker ikke værdien og den er stadig stored i hukommelsen derfor ved sidste print statement læser den hele strengen

//3 Det kan man sikre ved at bruge et char array i stedet for at deklarere dem enkeltvis (string) - ved at bruge printf('%c') for char så kan den læse hele arrayet
//så ville man definere variablen som følgende: char str[] = "dog";