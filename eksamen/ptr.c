#include <stdio.h>
 
#define firstName 'Lucas'
#define lastName 'Bastin'

int main() {
    int i = 5;

    char *ptr1= "Hello world";
    int *ptr2;
    ptr2 = &i;
    typedef struct name_record
    {
        char first_name [10];
        char last_name [10]; 
    } name;
    name myName;

    

    printf("Size: %lu Address: %p\n", sizeof(ptr1), ptr1);
    printf("Size: %lu Address: %p\n", sizeof(ptr2), (void *)ptr2);
    printf("Size: %lu Address: %p\n", sizeof(&myName), (void *)&myName);



    return 0;
}