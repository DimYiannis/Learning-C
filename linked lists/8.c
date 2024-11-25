/* Write a program in C to delete a node from the middle of a Singly Linked List.
Test Data and Expected Output :

Input the number of nodes : 3
 Input data for node 1 : 2
 Input data for node 2 : 5
 Input data for node 3 : 8

 Data entered in the list are :
 Data = 2
 Data = 5
 Data = 8

 Input the position of node to delete : 2

 Deletion completed successfully.

 The new list are  :
 Data = 2
 Data = 8
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
    int num;

    printf("\nInput the position of node to delete : ");
    scanf("%d", &num);

    if (head == NULL)
    {
        printf("List is empty, no node to delete.\n");
        return;
    }

    if (num == 1)
    {
        head = head->next;
        free(tmp);
        printf("\nDeletion completed successfully.");
        return;
    }

    tmp = head;
    prenode = head;

    for (int i = 1; i < num && tmp != NULL; i++) {
        prenode = tmp;
        tmp = tmp->next;
    }

     if (tmp == NULL || tmp->next == NULL && num != 1) {
        printf("Deletion cannot be possible from that position.\n");
        return;
    }

    prenode->next = tmp->next;
    free(tmp);
    printf("\nDeletion completed successfully.");
}