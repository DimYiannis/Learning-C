/* Write a program in C to delete the last node of a Singly Linked List.
Test Data :
Input the number of nodes : 3
Input data for node 1 : 1
Input data for node 2 : 2
Input data for node 3 : 3
Expected Output :

 Data entered in the list are :
 Data = 1
 Data = 2
 Data = 3

 The new list after deletion the last node are  :
 Data = 1
 Data = 2
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
void deletion();

int main()
{
    int num;

    printf("\ninput the number of nodes : ");
    scanf("%d", &num);
    createlist(num);
    printf("\nData entered in the list are :");
    displaylist();
    deletion();
    printf("\nThe new list is  :");
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
    }

    printf("\nInput data for node 1 : ");
    scanf("%d", &head->data);

    head->next = NULL;
    tmp = head;

    for (int i = 2; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("\nMemory allocation failed");
            break;
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

void deletion()
{
    struct node *tmp, *prenode;

    if (head == NULL)
    {
        printf("The list is already empty.\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    prenode = head;
    tmp = prenode->next;

    while (tmp->next != NULL)
    {
        prenode = tmp;
        tmp = tmp->next;
    }

    prenode->next = NULL;
    free(tmp);
}