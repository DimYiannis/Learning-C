#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, i, arr1[15];
    int *pt;

    printf("\n\n Pointer : Print the elements of an array in reverse order :\n");
    printf("----------------------------------------------------------------\n");

    printf(" Input the number of elements to store in the array (max 15) : ");
    scanf("%d", &n);

    pt = &arr1[0];

    printf(" Input %d number of elements in the array : \n", n);
    for (i = 0; i < n; i++)
    {
        printf(" element - %d : ", i + 1);
        scanf("%d", pt); // Accepting the address of the value
        pt++;
    }

    pt = &arr1[n - 1];

    printf("\n The elements of array in reverse order are :");
    for (i = n; i > 0; i--)
    {
        printf("\n element - %d : %d  ", i, *pt); // Printing the element and its value
        pt--;                                     // Moving the pointer to the previous element
    }

    printf("\n\n");
}
