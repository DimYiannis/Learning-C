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

void myfunction(char *text)
{

    int n = strlen(text); // Get the length of the string

    // Create a new array to store the reversed string
    char reversedText[n + 1]; // n + 1 for the null terminator
    reversedText[n] = '\0';   // Null-terminate the reversed string

    for (int i = 0; i < n; i++)
    {
        reversedText[i] = text[n - i - 1];
    }
    printf("Reversed string: %s \n", reversedText);
}

int main()
{

    char text[] = "w3resource";

    char newtext;
    // printf("\n Input a string : ");
    // scanf("%s", &text);

    printf("\n Pointer : Print a string in reverse order : ");
    printf("\n ------------------------------------------------");
    printf("\n Original string: %s", text);
    printf("\n ");
    myfunction(text);

    return 0;
}