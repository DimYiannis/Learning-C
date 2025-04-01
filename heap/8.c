/*
8. Next Greater/Smaller Element Challenges

Write a C program to find the next greater element for each element in an array using a stack. Return -1 if there is no next-larger element.

Expected Output:

Elements in the array are: 1 2 3 4 5 6
The next larger elements are:
1 --> 2
2 --> 3
3 --> 4
4 --> 5
5 --> 6
6 --> -1

Elements in the array are: 6 5 4 3 2 1 0
The next larger elements are:
0 --> -1
1 --> -1
2 --> -1
3 --> -1
4 --> -1
5 --> -1
6 --> -1

Elements in the array are: 3 7 5 9 3 2 4 1 4
The next larger elements are:
3 --> 7
5 --> 9
7 --> 9
2 --> 4
3 --> 4
1 --> 4
4 --> -1
9 --> -1
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int stack[MAX_SIZE];
int top = -1;

void push(char data)
{
    if (top == MAX_SIZE - 1)
    {
        printf("stack is full\n");
    }
    stack[++top] = data;
}

int pop()
{
    if (top == -1)
    {
        printf("stack is empty\n");
        return -1;
    }
    return stack[top--];
}

void next_greater(char *arr)
{
    for (int i = 0; arr[i] != '\0' && arr[i] !='\n'; i++)
    {
        int found = 0;

        for (int j = 1; arr[j] != '\0' && arr[j] !='\n'; j++)
        {
            if (arr[i] < arr[j])
            {
                push(arr[j]);
                found = 1;
                break;
            }
        
        }
        if (!found)
        {
            push(-1);
        }
        
    }
    for (int i = 0; i<top; i++)
    {
        if (stack[i] == -1)
        {
            printf("%c --> -1 \n", arr[i]);
        }
        else 
        {
            printf("%c --> %c \n", arr[i], stack[i]);
        }
    }
    
}

int main()
{
    char arr[MAX_SIZE];
    printf("insert numbers\n");
    fgets(arr, MAX_SIZE, stdin);
    printf("Elements in the array are: ");
    for (int i = 0; arr[i] != '\0'; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
    printf("The next larger elements are: \n");
    next_greater(arr);
}