#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y, int *z);

int main()
{

    int element1;
    int element2;
    int element3;

    printf("\n Input the value of 1st element : ");
    scanf("%d", &element1);
    printf(" Input the value of 2nd element : ");
    scanf("%d", &element2);
    printf(" Input the value of 3rd element : ");
    scanf("%d", &element3);
    printf(" Expected Output: \n");

    printf("\n The value before swapping are :\n");
    printf(" element 1 = %d \n element 2 = %d \n element 3 = %d \n", element1, element2, element3);

    // swapping
    swap(&element1, &element2, &element3);

    printf("\nThe value after swapping are :");
    printf("\n element 1 = %d \n  element 2 = %d \n  element 3 = %d \n", element1, element2, element3);
    printf("\n element 1 = %p \n  element 2 = %p \n  element 3 = %p \n", &element1, &element2, &element3);
}

void swap(int *x, int *y,int *z) {
    int tmp;

    tmp = *x;
    *x = *z;
    *z = *y;
    *y = tmp; 
}
