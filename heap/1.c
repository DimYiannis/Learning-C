/*
Write a C program to implement a stack using an array with push and pop operations.

Expected Output:

Elements in the stack are: 3 5 4 3 2 1 
*/

#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE]; //array to implement the stack
int top = -1; // variable to keep track of the top of the heap

//function to push an element onto the stack
void push(int data) {
    if (top == MAX_SIZE - 1 ) { //check for stack overflow
        printf("overflow stack!");
        return;
    }
    top++; // move the top pointer to the next position
    stack[top] = data; // add the data to the stack at the current top posiiton
}

// function to pop an element from the stack
int pop() {
    if (top == -1) { //check if stack is empty
        printf("stack is empty");
        return -1;
    }
    int data = stack[top]; //get the data at the top of the stack
    top--; //move the top pointer down to the previous position
    return data; // return the popped data
}

int main() {
    //pushing elements onto the stack
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(3); //attempting to push another element when the stack is full

    printf("elements in the stack are: ");
    //popping and printing elements until the stack is empty
    while (top != -1) {
        printf("%d", pop()); //display the poped element
    }
    printf("\n");
    return 0;
}