/*
Write a program in C to create a singly linked list of n nodes and count the number of nodes.
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

 Total number of nodes = 3
*/
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
} *head;

void createlist(int n);
void displaylist();

int main()
{
    int num;

    printf("\nInput the number of nodes : ");
    scanf("%d", &num);

    if (num <= 0)
    {
        printf("Invalid number of nodes.\n");
    }
    else
    {
        createlist(num);
        printf("\nData entered in the list are:\n");
        displaylist();
    }

    return 0;
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
            printf("Memory allocation failed\n");
            return;
        }
        printf("\nInput data for node %d : ", i);
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
    int n = 0;
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    tmp = head;
    printf("\nData entered in the list are :");
    while (tmp != NULL)
    {
        n++;
        printf("\nData = %d", tmp->data);
        tmp = tmp->next;
    }
    printf("\nTotal number of nodes = %d", n);
}