#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 3

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

int isfull(int top)
{
    return (top == MAX_SIZE - 1);
}

void push(int *stack, int *top, int item)
{
    if (isfull(*top))
    {
        printf("stack is full\n");
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

int main()
{
    int *stack = createstack();
    int top = -1;
    printf("stack size: %d ", MAX_SIZE);

    push(stack, &top, 1);
    push(stack, &top, 2);
    push(stack, &top, 3);

    printf("\noriginal stack: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    // Demonstrating stack overflow condition by trying to push another value
    printf("\nPush another value and check if the stack is full or not!\n");
    push(stack, &top, 4);

    free(stack);

    int *stack1 = createstack();
    int top1 = -1, result;
    printf("\nstack size: %d ", MAX_SIZE);

    push(stack1, &top1, 10);
    push(stack1, &top1, 20);

    printf("\n original stack: ");
    for (int i = 0; i <= top1; i++)
    {
        printf("%d ", stack1[i]);
    }

    printf("\ncheck the said stack is full or not\n");
    result = isfull(top1);
    if (result == 1)
    {
        printf("stack is full");
    }
    else
    {
        printf("stack is not full");
    }    
    
    free(stack1);
    return 0;
}