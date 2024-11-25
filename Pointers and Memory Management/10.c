/* 10. Write a program in C to calculate the length of a string using a pointer.
Test Data :
Input a string : w3resource
Expected Output :

The length of the given string w3resource
is : 10     */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char text[100];
    int n;

    printf("\nTest Data :");
    printf("Input a string : ");
    scanf("%s", text);
    n = strlen(text);

    printf("\nThe length of the given string %s is : %d", text, n);

    return 0;

    /*
        Function to calculate the length of the string

        int calculatelength(*ch) {
            
            int ctr = 0

            while (*ch =! '\0') {
            ctr++;
            *ch++;
        }

        return ctr;

        }
    */
}
