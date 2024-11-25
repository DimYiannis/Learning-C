#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void factorial(int x, int *result);

int main() {

    int n;
    int result;

    printf("\n Input a number : ");
    scanf("%d", &n);

    // factorial
    factorial(n, &result);

}

void factorial(int x, int *result) {
    
    int fact;

    if (x< 0) {
        printf("Error! Factorial of a negative number doesn't exist.");
    }
    else {
        for (int i =1; i<= x; i++) {
            fact *= i;
        }
         printf("Factorial of %d = %d", x, fact);
    }

}