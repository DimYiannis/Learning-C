#include <stdio.h>
#include <stdlib.h>
// pointers are type of data, they provide the memory address
int main()
{

    int age = 30;
    int * pAge = &age; // this pointer var is storing the memory address of the age var
    

    printf("age's memory address: %p\n", &age);

    return 0;
}
