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

void push(char data) {
    if (top == MAX_SIZE - 1)
    {
        printf("stack is overflown\n");
    }
    char *ptr = data; //pointer to the beginning of the string
    while (*ptr != '\0'  && *ptr !='\n')
    {
        stack[++top] = *ptr;
        ptr++;
    }
}

int pop() {
    if (top == -1)
    {
        return 0;
    }
    return stack[top--];
}

int balance(int top) {
    if (stack[top] == ')' || stack[top] == '}' || stack[top] == ']')
    return 0;
}

int main() {
    char data[MAX_SIZE];
    printf("Input an expression in parentheses  : ");
    fgets(data, MAX_SIZE, stdin);
    printf("%s", data);
    push(data);
}