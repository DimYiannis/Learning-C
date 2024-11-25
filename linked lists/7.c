/*Write a program in C to delete the first node of a Singly Linked List.
Test Data :
Input the number of nodes : 3
Input data for node 1 : 2
Input data for node 2 : 3
Input data for node 3 : 4
Expected Output :

 Data entered in the list are :
 Data = 2
 Data = 3
 Data = 4

 Data of node 1 which is being deleted is :  2

 Data, after deletion of first node :
 Data = 3
 Data = 4 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head;

void createlist(int n);
void displaylist();
void deletion();

int main()
{
    int num;

    printf("\nInput the number of nodes : ");
    scanf("%d", &num);
    createlist(num);
    displaylist();
    deletion();
    displaylist();
}

void createlist(int n)
{
    struct node *tmp, *newnode;
    int data;

    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("\nMemory allocation failed");
        return;
    }

    printf("\nInput data for node 1: ");
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

        printf("\nInput data for node %d: ", i);
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

    printf("\nData entered in the list are : ");

    tmp = head;

    while (tmp != NULL)
    {
        printf("\nData = %d", tmp->data);
        tmp = tmp->next;
    }
}

void deletion()
{
    struct node *tmp;
    tmp = head;

    if (head == NULL)
    {
        printf("List is empty, no node to delete.\n");
        return;
    }

    printf("\nData of node 1 which is being deleted is :  %d", tmp->data);

    head = head->next;
    free(tmp);

    printf("\nData, after deletion of first node :");
}