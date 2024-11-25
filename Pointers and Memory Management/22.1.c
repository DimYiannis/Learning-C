/*22. Write a program in C to print a string in reverse using a pointer.
Test Data :
Input a string : w3resource
Expected Output :

 Pointer : Print a string in reverse order :
------------------------------------------------
 Input a string : w3resource
 Reverse of the string is : ecruoser3w */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char str1[50];
    char revstr[50];
    char *strptr = str1;
    char *revptr = revstr;
    int i=0;

    printf("\nInput a string : ");
    scanf("%s", str1);

    while (*strptr) {
        strptr++;
        i++;
    }

    while (i>0) {
        strptr--;
        *revptr = *strptr ;       
        revptr++;
        i--;

    }

    *revptr = '\0';
    

    printf("reverse of the string is : %s", revstr);

return 0;
}