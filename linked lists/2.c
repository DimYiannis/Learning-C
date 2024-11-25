/*
 Write a program in C to create a singly linked list of n nodes and display it in reverse order.
Test Data :
Input the number of nodes : 3
Input data for node 1 : 5
Input data for node 2 : 6
Input data for node 3 : 7
Expected Output :

 Data entered in the list are :                                                                               
 Data = 5                                                                                                     
 Data = 6                                                                                                     
 Data = 7                                                                                                     
                                                                                                              
 The list in reverse are :                                                                                    
 Data = 7                                                                                                     
 Data = 6                                                                                                     
 Data = 5 
*/
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
} *head;

// Function declarations
void createNodeList(int n);
void displayList();
void displayListReverse(struct node *current);

int main() {
    int num;

    printf("\nInput the number of nodes: ");
    scanf("%d", &num);

    if (num <= 0) {
        printf("Invalid number of nodes.\n");
    } else {
        createNodeList(num);
        printf("\nData entered in the list are:\n");
        displayList();
        printf("\nThe list in reverse are:\n");
        displayListReverse(head);
    }

    return 0;
}

void createNodeList(int n) {
    struct node *newNode, *tmp;
    int data;

    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Input data for node 1: ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;
    tmp = head;

    for (int i = 2; i <= n; i++) {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Input data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        tmp->next = newNode;
        tmp = tmp->next;
    }
}

void displayList() {
    struct node *tmp;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    tmp = head;
    while (tmp != NULL) {
        printf("Data = %d\n", tmp->data);
        tmp = tmp->next;
    }
}

void displayListReverse(struct node *current) {
    if (current == NULL) {
        return;
    }

    displayListReverse(current->next); 
    printf("Data = %d\n", current->data);
}
// recursion till it reaches the end of the list 
//and then starts to print the values