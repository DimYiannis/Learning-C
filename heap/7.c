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
    if (top == MAX_SIZE)
    {
        printf("stack is overflown\n");
        return -1;
    }
    top++;
    stack[top] = data;
}

int balance(int *top) {

}

int main() {
    char data[MAX_SIZE];
    printf("Input an expression in parentheses  : ");
    scanf("%s", data);
    push(data);
}