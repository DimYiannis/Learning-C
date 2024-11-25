#include <stdio.h>
#include <stdlib.h>

int bigger(int *a, int *b);

int main() {

    int fnum, secnum, larger;

    printf("\nInput the first number : ");
    scanf("%d", &fnum);    
    printf("\nInput the second number : ");
    scanf("%d", &secnum);

    larger = bigger(&fnum, &secnum);

    printf("\nThe number %d is larger. ", larger );  

    return 0;  

}

int bigger(int *a , int *b) {
    if (*a>*b) {
        return *a;
    } else if (*a<*b) {
        return *b;
    } else {
        printf("Numbers are equal.");
        return *a;
    }
}