#include <stdlib.h>
#include <stdio.h>

int main() {

    int i = 42;

    // Address-of stack-allocated variable

    int* p = &i;

    // Get the value by dereferencing p
    int value = *p;

    // Can also set the value this way
    *p = 13;

    printf("address of stack-allocated variable: %p", p);
    printf("\nGet the value by dereferencing p: %d", *p);

    return 0;

    
}