/*Write a C program that converts a singly linked list into a string and returns it.
Test Data and Expected Output :


Linked List: Convert a Singly Linked list into a string
-------------------------------------------------------------
Input the number of nodes: 3
 Input data for node 1 : 10
 Input data for node 2 : 20
 Input data for node 3 : 30

Return data entered in the list as a string:
The linked list: 10 20 30
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head;

void createlist(int n);
void display(int *arr);

int main()
{
    int n;
    
    printf("\nInput the number of nodes: ");
    scanf("%d", &n);
    createlist(n);
    printf("\nReturn data entered in the list as a string: ");
    int arr[n];
    display(arr);

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
            break;
        }

        printf("\nInput data for node %d: ", i);
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        tmp->next = newnode;
        tmp = tmp->next;
    }
}

void display(int *arr)
{
    struct node *tmp;
    tmp = head;
    int num = 0;

    while (tmp != NULL)
    {
        arr[num] = tmp->data;
        tmp = tmp->next;
        num++;
    }
}