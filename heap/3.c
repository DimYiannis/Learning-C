/*
Write a C program to check a stack is full or not using an array with push and pop operations.

Expected Output:

Stack size: 3
Original Stack: 1 2 3 
Push another value and check if the stack is full or not!
Stack is full!

Stack size: 3
Original Stack: 10 20 
Check the said stack is full or not!
Stack is not full!
*/

#include <stdio.h>

#define MAX_SIZE 3

int stack[MAX_SIZE]; //array to implement the stack
int top = -1; // variable to keep track of the top of the heap

void push(int data) {
    if (top==MAX_SIZE-1) {
        printf("Stack is full\n");
        return;
    }
    top++; //move the top pointer to the next position
    stack[top] = data; // add the data to the stack at the current top position
}

int pop() {
    if (top==-1)
    {
        printf("stack underflow \n");
        return -1;
    }
    int data = stack[top]; //get data from the top of the stack
    top--; //move the top pointer down to the previous position
    return data; //return the poppde data
}

void display() {
    printf("Stack size:  %d\n" , MAX_SIZE);
    printf("Original Stack: ");
    if (top==-1)
    {
        printf("stack is empty\n");
        return;
    }
    for (int i = 0; i<=top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
    
}

void check_full() {
    if (top==MAX_SIZE-1)
    {
        printf("Stack is full!\n");
    }
    else {
        printf("Stack is not full!\n");
    }
    
}

int main() {
    printf("test case 1\n");
    display(); //initially empty stack
    check_full(); //check if the stack is full
    push(1);
    push(2);
    push(3);
    display(); //display stack after pushing 3 elements
    check_full(); //check if the stack is full after pushing 3 elements

    printf("\ntest case 2: \n");
    top = -1; //reset stack
    push(10);
    push(20);
    display();
    check_full();

    return 0;
}