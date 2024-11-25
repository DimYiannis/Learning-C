#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char name[] = "a";
    char * pName = name;

    printf("\n %s", name);
    printf("\n %p", &name);

     strcpy(pName, "Y");

    // Print the updated values
    printf("\nUpdated value of variable: %s", name);
    printf("\nUpdated value stored in pointer: %p", pName);

    return 0;
}