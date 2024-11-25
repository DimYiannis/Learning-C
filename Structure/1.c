#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int age;
    float total;
};

int main() {

    struct Student student1={"alex", 22, 4.5}, student2={"john", 23, 4.9};

    printf("name: %s age: %d mark: %.2f ", student1.name, student1.age,student1.total);
    printf("name: %s age: %d mark: %.2f ", student2.name, student2.age,student2.total);
}