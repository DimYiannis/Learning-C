#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n = 4;
    int *ages;
    ages = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < 4; i++)
    {
        printf("\nType 4 values:");
        printf("\ninput element: ");
        scanf("\n %d", ages + i);
    }

    for (int i = 0; i < n; i++)
    {
        printf("\narray element : %d ", *(ages + i));
    }

    n = 6;

    ages = realloc(ages, n * sizeof(int));

    ages[4] = 32;
    ages[5] = 59;

    printf("Newly Allocated Memory\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", *(ages + i));
    }

    free(ages); // The free(ages) statement releases the memory back to the system, making it available for other parts of your program or other programs to use. The contents of the memory block are no longer guaranteed to be valid or unchanged after the call to free.

    return 0;
}
