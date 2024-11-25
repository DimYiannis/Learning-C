/*Write a program in C to insert a new node at the end of a Singly Linked List.
Test Data and Expected Output :

Input the number of nodes : 3
 Input data for node 1 : 5
 Input data for node 2 : 6
 Input data for node 3 : 7

 Data entered in the list are :
 Data = 5
 Data = 6
 Data = 7

 Input data to insert at the end of the list : 8

 Data, after inserted in the list are :
 Data = 5
 Data = 6
 Data = 7
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
void insert(int data2);

int main()
{

    int num;
    int data2;

    printf("\nInput the number of nodes : ");
    scanf("%d", &num);
    createlist(num);
    displaylist();
    printf("\nInput data to insert at the end of the list : ");
    scanf("%d", &data2);
    insert(data2);
    displaylist();
}

void createlist(int n)
{
    struct node *newnode, *tmp;
    int data;

    printf("\nInput data for node 1 : ");
    scanf("%d", &data);

    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("\nmemory allocation failed");
        return;
    }

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

        printf("\nInput data for node %d : ", n);
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;


        tmp->next = newnode;
        tmp = tmp->next;
    }
}

void displaylist() {
    struct node *tmp;

    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    tmp=head;
    printf("\nData entered in the list are : ");

    while (tmp!=NULL)
    {
        printf("\nData = %d", tmp->data);
        tmp = tmp->next;
    }
}

void insert(int data2) {
    struct node *tmp, *lastnode;

    lastnode = (struct node *)malloc(sizeof(struct node));
    if (lastnode==NULL)
    {
        printf("\'nmemoryallocation failed");
        return;
    }

    lastnode->data = data2;
    lastnode->next = NULL;
    tmp=head;
    
    while (tmp->next!=NULL)
    {
        tmp = tmp->next;
        tmp->next =lastnode;
    }
    
}