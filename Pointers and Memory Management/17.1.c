#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n, arr1[5];
    int *pt;

    printf("\ninput the number of elements: \n");
    scanf("%d", &n);
   
   pt = &arr1[0];

    printf("\nenter the values for %d elements:\n", n);

    for (int i = 0; i < n; i++)
    {
        printf(" element  - %d: \n", i+1);
        scanf("%d", pt); //accepting the address of the value
        pt++; //moving the pointer
    }
    
    pt = &arr1[n-1];

    printf("\n The elements of array in reverse order are :\n");

    for (int i = n; i > 0; i--)
    {
        printf("\nelement %d : %d",i, *pt);
        pt--;
    }
    
   


}
