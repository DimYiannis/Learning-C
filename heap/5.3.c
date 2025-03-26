/*
5. Dual Stack in Single Array Challenges

Write a C program to implement two stacks in a single array and performs push and pop operations for both stacks.

Expected Output:

Elements in Stack-1 are: 50 40 30 10
Elements in Stack-2 are: 70 60 50 40 20
*/

#include <stdio.h>
#include <stdlib.h>

// Node structure for the stack
struct Node {
    int data;
    struct Node* next;
};

// Stack structure
struct Stack {
    struct Node* top; // Top of the stack
};

// Function to initialize a stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = NULL;
    return stack;
}

// Function to check if stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Push operation
void push(struct Stack* stack, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = item;
    newNode->next = stack->top; // Point new node to the previous top
    stack->top = newNode;       // Update top
}

// Pop operation
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next; // Move top pointer
    free(temp); // Free memory
    return poppedValue;
}

// Function to print stack elements
void printStack(struct Stack* stack, int stackNum) {
    printf("Elements in Stack-%d are: ", stackNum);
    struct Node* temp = stack->top;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct Stack* stack1 = createStack();
    struct Stack* stack2 = createStack();

    // Push elements into Stack 1
    push(stack1, 50);
    push(stack1, 40);
    push(stack1, 30);
    push(stack1, 10);
    printStack(stack1, 1); // Output: 10 30 40 50

    // Push elements into Stack 2
    push(stack2, 70);
    push(stack2, 60);
    push(stack2, 50);
    push(stack2, 40);
    push(stack2, 20);
    printStack(stack2, 2); // Output: 20 40 50 60 70

    // Pop elements from Stack 1
    printf("Popped from Stack-1: %d\n", pop(stack1)); // Output: 10
    printStack(stack1, 1);

    // Pop elements from Stack 2
    printf("Popped from Stack-2: %d\n", pop(stack2)); // Output: 20
    printStack(stack2, 2);

    return 0;
}
