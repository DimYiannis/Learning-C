/*1. Write a program in C to create and display a Singly Linked List.
Test Data :
Input the number of nodes : 3
Input data for node 1 : 5
Input data for node 2 : 6
Input data for node 3 : 7
Expected Output :

 Data entered in the list :
 Data = 5
 Data = 6
 Data = 7 */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head;

void createNodeList(int n);
void displayList();

int main()
{
    int num;

    printf("\nInput the number of nodes :");
    scanf("%d", &num);
    if (num <= 0)
    {
        printf("Invalid number of nodes.\n");
    }
    else
    {
        createNodeList(num);
        printf("\nData entered in the list:\n");
        displayList();
    }

    return 0;
}

void createNodeList(int n)
{
    struct node *newNode, *tmp;
    int data;

    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("memory allocation failed\n");
        return;
    }

    printf("Input data for node 1: ");
    scanf("%d", &data);

    (*head).data = data;
    head->next = NULL;
    tmp = head;

    for (int i = 2; i <= n; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("memory allocation failed\n");
            return;
        }

        printf("input data for node %d: ", i);
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        tmp->next = newNode;
        tmp = tmp->next;
    }
}

void displayList()
{
    struct node *tmp;
    if (head == NULL)
    {
        printf("list is empty. \n");
        return;
    }

    tmp = head;
    while (tmp != NULL)
    {
        printf("data = %d\n", tmp->data);
        tmp = tmp->next;
    }
}