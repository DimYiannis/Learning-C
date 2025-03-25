/*
5. Dual Stack in Single Array Challenges

Write a C program to implement two stacks in a single array and performs push and pop operations for both stacks.

Expected Output:

Elements in Stack-1 are: 50 40 30 10
Elements in Stack-2 are: 70 60 50 40 20
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// create empty stack
int *createstack()
{
    int *stack = (int *)malloc(MAX_SIZE * sizeof(int));
    return stack;
}
// check if stack is empty
int isempty(int top)
{
    return (top == -1);
}

// check stack is full
int isfull(int top)
{
    return (top == MAX_SIZE - 1);
}

void push(int *stack, int *top, int item)
{
    if (isfull(*top))
    {
        printf("stack is full");
        return;
    }
    stack[++(*top)] = item;
}

int pop(int *stack, int *top)
{
    if (isempty(*top))
    {
        printf("stack is empty\n");
        return -1;
    }
    return stack[(*top)--];
}

int main() {
    int *stack1 = createstack();
    int top1 = -1;
    push(stack1, &top1, 50);
    push(stack1, &top1, 40);
    push(stack1, &top1, 30);
    push(stack1, &top1, 10);

    printf("\nElements in Stack-1 are: ");
    for (int i = 0; i <= top1; i++)
    {
        printf("%d ", stack1[i]);
    }
    printf("\n");

    int *stack2 = createstack();
    int top2 = -1;

    push(stack2, &top2, 70);
    push(stack2, &top2, 60);
    push(stack2, &top2, 50);
    push(stack2, &top2, 40);
    push(stack2, &top2, 20);

    printf("Elements in Stack-2 are:");
    for (int i = 0; i <= top2; i++)
    {
        printf("%d ", stack2[i]);
    }
    
}