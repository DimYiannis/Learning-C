/* 5. Write a program in C to add numbers using call by reference.
Test Data :
Input the first number : 5
Input the second number : 6
Expected Output :

The sum of 5 and 6  is 11 */

#include <stdio.h>
#include <stdlib.h>



int main() {

    int num1;
    int num2;
    int sum, *pNum1, *pNum2;


    printf("\n Test Data");
    printf("\n Input the first number : ");
    scanf("%d", &num1);

    printf("\n Input the second number : ");
    scanf("%d", &num2);

    pNum1 = &num1;
    pNum2 = &num2;

    sum= *pNum1 + *pNum2;

    printf("\nExpected Output :\n");
    printf("\n The sum of %d and %d is : %d",num1, num2, sum);

    return 0;
}

