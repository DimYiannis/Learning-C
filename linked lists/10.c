/*Write a program in C to search for an existing element in a singly linked list.
Test Data and Expected Output :

Input the number of nodes : 3

 Input data for node 1 : 2
 Input data for node 2 : 5
 Input data for node 3 : 8

 Data entered in the list are :
 Data = 2
 Data = 5
 Data = 8

 Input the element to be searched : 5
 Element found at node 2
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head;

void createlist(int n);
void display();
void find();

int main()
{

    int num;

    printf("\ninput the number of nodes : ");
    scanf("%d", &num);
    createlist(num);
    printf("\nData entered in the list are :");
    display();
    find();
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

void display()
{
    struct node *tmp;
    tmp = head;

    while (tmp != NULL)
    {
        printf("\n%d", tmp->data);
        tmp = tmp->next;
    }
}

void find()
{
    struct node *tmp;
    int n;
    tmp = head;
    int count = 0;

    printf("\nInput the element to be searched :");
    scanf("%d", &n);

    while (tmp != NULL)
    {
        count++;
        tmp = tmp->next;
    }

    tmp = head;

    for (int i = 1; i <= count; i++)
    {
        if (n == tmp->data)
        {
            printf("\nElement found at node %d ", i);
        }
        tmp = tmp->next;
    }
}