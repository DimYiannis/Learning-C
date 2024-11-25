/*Write a C program that converts a singly linked list into an array and returns it.
Test Data and Expected Output :


Linked List: Convert a Singly Linked list into a string
-------------------------------------------------------------
Input the number of nodes: 3
 Input data for node 1 : 10
 Input data for node 2 : 20
 Input data for node 3 : 30

Return data entered in the list as a string:
The linked list: 10 20 30*/

#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
} *head;

void createlist(int n);
void tostring(int *arr);

int main()
{
    int n;

    printf("\nInput the number of nodes: ");
    scanf("%d", &n);
    createlist(n);
    printf("\nReturn data entered in the list as a string: ");
    int arr[n];
    tostring(arr);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
}

void createlist(int n)
{
    struct node *tmp, *newnode;
    int data;

    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("\nmemory allocation failed");
    }

    printf("\ninput data for node 1: ");
    scanf("%d", &head->data);

    head->next = NULL;
    tmp = head;

    for (int i = 2; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("\nmemory allocation failed");
        }

        printf("\ninput data for node %d: ", i);
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        tmp->next = newnode;
        tmp = tmp->next;
    }
}

void tostring(int *arr)
{
    struct node *tmp;
    tmp = head;
    int n = 0;

    while (tmp !=NULL)
    {
        arr[n] = tmp->data;
        tmp = tmp->next;
        n++;
    }
    
}