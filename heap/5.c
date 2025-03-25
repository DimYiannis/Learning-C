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

// global array for both stacks
int stack[MAX_SIZE];

// top pointers for two stack
int top1 = -1;       // starts from left
int top2 = MAX_SIZE; // starts from right

// check stack 1 is full
int isfull()
{
    return (top1 + 1 == top2); // if stacks meet, array is full
}

// check if stack 1 is empty
int isempty1()
{
    return (top1 == -1);
}

// check stack 2 is empty
int isempty2()
{
    return (top2 == MAX_SIZE);
}

void push1(int item)
{
    if (isfull())
    {
        printf("stack is full");
        return;
    }
    stack[++top1] = item;
}

void push2(int item)
{
    if (isfull())
    {
        printf("stack is full");
        return;
    }
    stack[--top2] = item;
}

int pop1()
{
    if (isempty1())
    {
        printf("stack 1 is empty\n");
        return -1;
    }
    return stack[top1--];
}

int pop2()
{
    if (isempty2)
    {
        printf("stack 2 is empty");
        return -1;
    }
    stack[top2++];
}

void printstack1()
{
    printf("elements in stack-1 are: ");
    for (int i = 0; i <= top1; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void printstack2()
{
    printf("elements in stack-2 are: ");
    for (int i = MAX_SIZE - 1; i >= top2; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
int main()
{

    push1(50);
    push1(40);
    push1(30);
    push1(10);
    printstack1();

    push2(70);
    push2(60);
    push2(50);
    push2(40);
    push2(20);
    printstack2();

    return 0;
}