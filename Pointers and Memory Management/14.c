/*
Write a program in C to sort an array using a pointer.

Test Data :
Input the number of elements to store in the array : 5
Input 5 number of elements in the array :
element - 1 : 25
element - 2 : 45
element - 3 : 89
element - 4 : 15
element - 5 : 82
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *numbers = NULL;

    printf("\n Test Data : ");
    printf("\nInput the number of elements to store in the array : ");
    scanf("%d", &n);
    /*int numbers[100];*/
    numbers = (int *)malloc(n * sizeof(int));

    if (numbers == NULL)
    {
        printf("Memory allocation failed\n");
        return 1; // Return with error code
    }

    printf("\nInput %d number of elements in the array :", n);

    for (int i = 0; i < n; i++)
    {
        printf("\nelement - %d :", i + 1);
        scanf("%d", &numbers[i]);
    }

    /*sorting logic*/
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {

            if (numbers[i] > numbers[j])
            {

                /*switch*/
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
            }
        }
    }

    printf("\nThe elements in the array after sorting :\n");

    for (int i = 0; i < n; i++)
    {
        printf("element - %d : %d \n", i + 1, numbers[i]);
    }

    free(numbers);

    return 0;
}