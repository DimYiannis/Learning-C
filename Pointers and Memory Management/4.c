/*4. Write a program in C to add two numbers using pointers.
Test Data :
Input the first number : 5
Input the second number : 6*/

#include <stdio.h>
#include <stdlib.h>



int main() {

    int num1;
    int num2;
    int sum, *pNum1, *pNum2;

    printf("\n Input the first number : ");
    scanf("%d", &num1);

    printf("\n Input the second number : ");
    scanf("%d", &num2);

    pNum1 = &num1;
    pNum2 = &num2;

    sum= *pNum1 + *pNum2;

    printf("\nExpected Output :\n");
    printf("\n The sum of the entered numbers is : %d", sum);

    return 0;
}

