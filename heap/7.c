/*
7. Balanced Parentheses and Delimiters

Write a C program that checks whether a string of parentheses is balanced or not using stack.

Expected Output:

Input an expression in parentheses: {[])
The expression is not balanced.
 -----------------------------------------
 Input an expression in parentheses: ((()))
The expression is balanced.
 -----------------------------------------
 Input an expression in parentheses: ())
The expression is not balanced.
 -----------------------------------------
 Input an text of parentheses: ([]){}[[(){}]{}]
The expression is balanced.
 -----------------------------------------
 Input an expression in parentheses: [(]))
The expression is not balanced.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(char data)
{
    if (top == MAX_SIZE - 1)
    {
        printf("stack is overflown\n");
    }
    stack[++top] = data;
}

int pop()
{
    if (top == -1)
    {
        return 0;
    }
    return stack[top--];
}

int balance(char *data)
{
    for (int i = 0; data[i] != '\0' && data[i] != '\n'; i++)
    {
        char ch = data[i];

        // push opening brackets onto the stack
        if (ch == '(' || ch == '[' || ch == '{')
        {
            push(ch);
        }

        // if its a closing bracket, check for matching opening bracket
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (top == -1) // stack is empty
            {            
                return 0; // not balanced
            }
            char topchar = pop(); // retrieve the last opening bracket from the stack

            // check if matching brackets
            if ((ch == ')' && topchar != '(') ||
                (ch == ']' && topchar != '[') ||
                (ch == '}' && topchar != '{'))
            {
                return 0; // Not balanced
            }
        }
    }

    // if stack is empty at the end, expression is balanced
    return (top == -1);
}

int main()
{
    char data[MAX_SIZE];
    printf("Input an expression in parentheses  : ");
    fgets(data, MAX_SIZE, stdin);
    if (balance(data))
    {
        printf("The expression is balanced.\n");
    }
    else
    {
        printf("The expression is not balanced.\n");
    }
    return 0;
}