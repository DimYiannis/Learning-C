#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head;

void createNodeList(int n);
void displaylist();
void reverse();

int main()
{
    int num;

    printf("\nInput the number of nodes: ");
    scanf("%d", &num);

    if (num <= 0)
    {
        printf("Invalid number of nodes.\n");
    }
    else
    {
        createNodeList(num);
        printf("\nData entered in the list:\n");
        displaylist();
        printf("\nThe list in reverse are :\n");
        reverse(head);
    }
}

void createNodeList(int n)
{

    struct node *newnode, *tmp;
    int data;

    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("\nMempty allocation failed\n");
        return;
    }

    printf("\nInput data for node 1: ");
    scanf("%d", &data);

    head->data = data;
    head->next = head; // Point to itself, circular nature
    head->prev = head;
    tmp = head;

    for (int i = 2; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
        printf("\nnput data for node %d :", i);
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = head; // Point to head, circular nature
        newnode->prev = tmp;

        tmp->next = newnode;
        head->prev = newnode;
        tmp = tmp->next;
    }
}

void displaylist()
{
    struct node *tmp;

    if (head == NULL)
    {
        printf("list is empty. \n");
        return;
    }

    tmp = head;

    do
    {
        printf("\ndata =  %d", tmp->data);
        tmp = tmp->next;
    } while (tmp != head);
}

void reverse()
{
    struct node *tmp;
    if (head == NULL)
    {
        printf("list is empty. \n");
        return;
    }

    tmp = head->prev;

    do
    {
        printf("\ndata = %d", tmp->data);
        tmp = tmp->prev;
    } while (tmp != head->prev);
}
