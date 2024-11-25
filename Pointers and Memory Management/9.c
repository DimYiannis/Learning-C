/* 9. Write a program in C to find the largest element using Dynamic Memory Allocation.
Test Data :
Input total number of elements(1 to 100): 5

Number 1: 5
Number 2: 7
Number 3: 2
Number 4: 9
Number 5: 8
Expected Output :

The Largest element is :  9.00 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *totalnum;
    int n, maxnum;

    printf("Test Data : ");
    printf("\n Input total number of elements(1 to 100): ");
    scanf("%d", &n);

    totalnum = (int *)malloc(n * sizeof(int));

    if (totalnum == NULL)
    {
        printf("Memory allocation failed. Exiting...");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nNumber %d: ", i + 1);
        scanf("%d", &totalnum[i]);
    }

    printf("\nExpected Output :\n");

     maxnum = totalnum[0] ;
    for (int i = 0; i < n; i++)
    {
        if (totalnum[i] > maxnum)
        {
            maxnum = totalnum[i] ;
        }
    }

    printf("The Largest element is : %d", maxnum);

    free(totalnum);

    return 0;
}
