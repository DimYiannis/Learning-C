/*Write a program in C to insert a new node at the beginning of a Singly Linked List.
Test Data and Expected Output :

 Input the number of nodes : 3
 Input data for node 1 : 5
 Input data for node 2 : 6
 Input data for node 3 : 7

 Data entered in the list are :
 Data = 5
 Data = 6
 Data = 7

 Input data to insert at the beginning of the list : 4

 Data after inserted in the list are :
 Data = 4
 Data = 5
 Data = 6
 Data = 7
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head;

void createlist(int n);
void displaylist();
void insert(int d);

int main()
{
    int num;
    int data2;

    printf("\nInput the number of nodes :");
    scanf("%d", &num);
    createlist(num);
    displaylist();
    printf("\nInput data to insert at the beginning of the list : ");
    scanf("%d", &data2);
    insert(data2);
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

    printf("\nInput data for node 1 :");
    scanf("%d", &data);

    head->data = data;
    head->next = newnode;
    tmp = head;

    for (int i = 2; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("\nmemory allocation failed");
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
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    tmp = head;
    printf("\nData entered in the list are : ");

    while (tmp != NULL)
    {
        printf("\nData = %d", tmp->data);
        tmp = tmp->next;
    }
}

void insert(int d)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("\nmemory allocation failed");
    }
    tmp->data = d;
    tmp->next = head;
    head=tmp;
}