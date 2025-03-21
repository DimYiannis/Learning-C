/*
Write a C program to implement a stack using a singly linked list.

Expected Output:

 Push data 1
 Push data 2
 Push data 3
 Push data 4

 Pop data: 4
 Pop data: 3
 Pop data: 2
 Pop data: 1

 Check a stack is empty or not?
 Stack is empty!*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL; //pointer to the top of the stack

void push(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); //allocate memory for the new node
    if (newNode==NULL)
    {
        printf("stack overflow. memory allocation failed. \n");
        return;
    }
    newNode->data = data; //assign new value
    newNode->next = top; // link new node to the stack and point to the previous top
    top = newNode; //newnode become the top of the stack
    printf("Push data %d\n", data);
}

int pop() {
    if (top==NULL)
    {
        printf("stack underflow. there are no elements to pop. \n");
        return -1;
    }
    Node* temp = top; //store current top
    int data = temp->data; // get data from top
    top = top->next; // move top to the next top
    free(temp); // free the memory of the removed node
    printf("Pop data: %d\n", data);
    return data; //return the erased value
}

void check_empty() {
    printf("\nCheck a stack is empty or not?\n");
    if (top == NULL) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack is NOT empty!\n");
    }
}

int main() {
    //push elements onto the stack
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    printf("\n");
    
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();

    check_empty();

    return 0;
}