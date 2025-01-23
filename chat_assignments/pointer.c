#include <stdio.h>

int main (){
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr; 

    printf("Original Array: \n");
    for (int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    
    }
    printf("\n");
    printf("Accessing the array using the pointer: \n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i)); // What does the pointer do here? the * dereferences the pointer, so that it can access the value of the array
    }
    printf("\n");

    printf("Doubling the array elements using a pointer: \n");

    for (int i = 0; i < 5; i++){
        *(ptr + i) *= 2; // The pointer points at the value of the element in the array, and then *2 the value = doubles it. 
        printf("%d ", *(ptr + i)); // the pointer now points at the value of the element in the array that has been doubled, at iterated through the loop and returns the doubled value inside each element of the array. 
    }
    printf("\n");

    printf("Accessing the elements in the array by moving the pointer: \n");
    ptr = arr; // The pointer is now pointing at the first element in the array.
    for (int i = 0; i < 5; i++){
        printf("%d ", *ptr); // The pointer is pointing at the value of the element in the array, and then the value is printed. 
        ptr++; // The pointer is moved to the next element in the array.
    }
    printf("\n");
    printf("Final array after modification: \n");
    for (int i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
    
}
