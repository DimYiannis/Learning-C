/*
Stack Sorting Variants

Write a C program to sort a given stack using another stack.

Expected Output:

Original stack: 1 5 5 2 3 8
Sorted stack: 1 2 3 5 5 8
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

int isempty(int top)
{
    return (top == -1);
}

int isfull(int top)
{
    return (top == MAX_SIZE - 1);
}

void push(int *stack, int *top, int item)
{
    if (isfull(*top))
    {
        printf("stack is full\n");
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

void sort_stack(int *original, int *top1, int* sorted, int* top2)
{
    while (!isempty(*top1)) {
        //get value off from original
        int temp = pop(original, top1);

        //if value in sorted is bigger than the one in original 
        //we sent it back to original and in its position the 
        //smaller value is placed
        while (!isempty(*top2) && sorted[*top2] > temp)
        {
            push(original, top1, pop(sorted, top2));
        }
        //add the erased value to the sorted stack
        push(sorted, top2, temp);
    }
}

void print_stack(int* stack, int top) {
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    int *original = createstack();
    int top1 = -1;

    push(original, &top1, 1);
    push(original, &top1, 5);
    push(original, &top1, 5);
    push(original, &top1, 2);
    push(original, &top1, 3);
    push(original, &top1, 8);

    printf("original elements: ");
    print_stack(original, top1);

    int *sorted = createstack();
    int top2 = -1;

    sort_stack(original, &top1, sorted, &top2);

    printf("sorted stack: ");
    print_stack(sorted, top2);

    free(original);
    free(sorted);
    return 0;
}