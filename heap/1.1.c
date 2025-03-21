//stack using a linked list

#include <stdio.h>
#include <stdlib.h>

//define a struct for stack nodes
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL; //pointer to the top of the stack

void push(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node)); //allocate memory for new node
    if (newNode ==NULL) {
        printf("stack overflow! memory allocation failed. \n");
        return;
    }
    newNode->data = data; //assign value
    newNode->next = top; //  new node point to the previous top node.
    top = newNode; // newNode becomes the new top of the stack.
}

int pop() {
    if (top ==NULL) {
        printf("stack underflow. no elements to pop. \n");
        return -1;
    }
    Node* temp = top; //store current top
    int data = temp->data; //get data from top
    top = top->next; //move top to the next node
    free(temp); //free the memory of removed node
    return data;
}

//function to display elements in the stack
void display() {
    if (top ==NULL)
    {
        printf("stack is empty. \n");
        return;
    }
    Node* temp = top;
    printf("elements in the stack are: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp ->next;
    }
    printf("\n");
}

int main() {
    //pushing elements onto the stack
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);

    display(); //show stack

    //popping elements
    printf("popped: %d\n", pop());
    printf("popped: %d\n", pop());

    dispaly();

    return 0;
}

