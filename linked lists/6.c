/*Write a program in C to insert a node in the middle of a Singly Linked List.
Test Data and Expected Output :

Input the number of nodes (3 or more) : 4
 Input data for node 1 : 1
 Input data for node 2 : 2
 Input data for node 3 : 3
 Input data for node 4 : 4

 Data entered in the list are :
 Data = 1
 Data = 2
 Data = 3
 Data = 4

 Input data to insert in the middle of the list : 5
 Input the position to insert new node : 3

 Insertion completed successfully.

 The new list is :
 Data = 1
 Data = 2
 Data = 5
 Data = 3
 Data = 4  */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head;

void createlist(int n);
void displaylist();
void insert(int num);

int main()
{
    int data;
    int num;

    printf("\nInput the number of nodes (3 or more) : ");
    scanf("%d", &num);
    createlist(num);
    printf("\n Data entered in the list are :");
    displaylist();
    insert(num);
    printf("\nThe new list is : ");
    displaylist();
}

void createlist(int n)
{
    struct node *newnode, *tmp;
    int data;

    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("\nmemory allocation failed");
        return;
    }

    printf("\nInput data for node 1 : ");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;
    tmp = head;

    for (int i = 2; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("\nmemory allocation failed");
            return;
        }

        printf("\nInput data for node %d :", i);
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        tmp->next = newnode;
        tmp = tmp->next;
    }
}

void displaylist()
{
    struct node *tmp;
    tmp = head;

    while (tmp != NULL)
    {
        printf("\n Data = %d", tmp->data);
        tmp = tmp->next;
    }
}

void insert(int num)
{
    struct node *tmp, *newnode;
    int position;
    int data;

    printf("\nInput data to insert in the middle of the list : ");
    scanf("%d", &data);

    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("\nmemory allocation failed");
        return;
    }

    newnode->data = data;
    newnode->next = NULL;
    tmp = head;

    printf("\nInput the position to insert new node : ");
    scanf("%d", &position);

    if (position <= 1 || position > num)
    {
        printf("\nPosition should be greater than 1 and less than or equal to the number of nodes.");
        return;
    }

    for (int i = 2; i <= position - 1; i++)
    {
        // Traverse to the node just before the insertion point
        tmp = tmp->next;
        if (tmp == NULL)
        {
            break;
        }
    }
    if (tmp != NULL)
    {
        newnode->next = tmp->next; // point to the next node
        tmp->next = newnode; // placing tmp node before the newnode
    }
    else
    {
        printf(" Insertion is not possible at the given position.\n");
    }
}