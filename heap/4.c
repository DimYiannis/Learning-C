/*
String Reversal Using Stack Variants

Write a C program that accepts a string and reverse it using a stack.

Expected Output:

Input a string: w3resource
 Reversed string using a stack is: ecruoser3w
*/

#include <stdio.h>
#include <stdlib.h>

char stack[100];

void reverse(char *text)
{
    int len=0;
    while (text[len]!='\0') //length of input
    {
        len++;
    }

    for (int i = 0; i < len; i++) //reverse the string
    {
        stack[i] = text[len-1-i];
    }

    stack[len] = '\0'; //null terminate the reversed string
}

int main()
{

    char *text = malloc(100 * sizeof(char));
    if (text==NULL)
    {
        printf("memory allocation failed\n");
        return 1;
    }
    

    printf("Input a string: ");
    scanf("%99s", text);

    reverse(text);
    printf("\nReversed string using a stack is: %s", stack);

    free(text);
    return 0;
}
