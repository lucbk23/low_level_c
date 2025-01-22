#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float grade;
};

int main (){
    struct Student s1;

    printf("Enter student name: ");
    scanf("%s", s1.name);

    printf("Enter student age: ");
    scanf("%d", &s1.age);

    printf("Enter student grade: ");
    scanf("%f", &s1.grade);

    printf("Student information:\n");
    printf("Student name: %s\n", s1.name);
    printf("Student age: %d\n", s1.age);
    printf("Student grade: %.2f\n", s1.grade);
    return 0;
}
