/* Write a C program to merge two sorted singly linked lists into a single sorted linked list.
Test Data and Expected Output :

Two sorted singly linked lists:
1 3 5 7
2 4 6

After merging the said two sorted lists:
1 2 3 4 5 6 7 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head1 = NULL, *head2=NULL;

void createlist(struct node **head, int n);
void tostring(struct node *head, int *arr);
void printlist(int *arr, int n);
void merge(int *arr1, int *arr2, int n1, int n2);

int main()
{
    int n1;
    int n2;

    printf("\nEnter the number of the nodes in the first single linked list: ");
    scanf("%d", &n1);
    printf("\nEnter the number of the nodes in the second single linked list: ");
    scanf("%d", &n2);

    createlist(&head1,n1);
    createlist(&head2, n2);

    int arr1[n1];
    int arr2[n2];

    tostring(head1, arr1);
    tostring(head2, arr2);

    printf("\nTwo sorted singly linked lists:");
    printlist(arr1, n1);
    printlist(arr2, n2);

    printf("\nAfter merging the said two sorted lists: ");
    merge(arr1, arr2, n1, n2);

    return 0;
}

void createlist(struct node **head, int n)
{
    struct node *tmp, *newnode;
    int data;

    *head = (struct node *)malloc(sizeof(struct node));
    if (*head == NULL)
    {
        printf("\n Memory allocation failed");
    }

    printf("\n input data for node 1: ");
    scanf("%d", &(*head)->data);
    (*head)->next = NULL;
    tmp = *head;

    for (int i = 2; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("\nmemory allocation failed");
        }

        printf("\n input data for node %d: ", i);
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        tmp->next = newnode;
        tmp = tmp->next;
    }
}

void tostring(struct node *head, int *arr)
{
    struct node *tmp;
    tmp = head;
    int n = 0;

    while (tmp != NULL)
    {
        arr[n] = tmp->data;
        tmp = tmp->next;
        n++;
    }
}

void printlist(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\n%d ", arr[i]);
    }
}

void merge(int *arr1, int *arr2, int n1, int n2)
{
    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            printf("\n %d", arr1[i]);
            i++;
        }
        else
        {
            printf("\n %d", arr2[j]);
            j++;
        }
    }

    // Print remaining elements if any
    while (i < n1) {
        printf("%d ", arr1[i]);
        i++;
    }

    while (j < n2) {
        printf("%d ", arr2[j]);
        j++;
    }
}