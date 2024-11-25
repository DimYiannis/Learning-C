/* 6. Write a program in C to find the maximum number between two numbers using a pointer.
Test Data :
Input the first number : 5
Input the second number : 6
Expected Output :

6 is the maximum number.  
*/

#include <stdio.h>
#include <stdlib.h>

void bigger(int num1, int num2, int *max, char text[]) {
    
    if (num1>num2) {
        *max = num1;
        printf("\n %d is the maximum number. ",num1);
    }else if  (num1<num2) {
        *max = num2;
        printf("\n %d is the maximum number. ",num2);
    } else {
        printf("%s",text);
    }
}

int main() {

    int num1;
    int num2;
    int max, *pNum1, *pNum2;
    char text[] = " Numbers are equal";


    printf("\n Test Data");
    printf("\n Input the first number : ");
    scanf("%d", &num1);

    printf("\n Input the second number : ");
    scanf("%d", &num2);

    pNum1 = &num1;
    pNum2 = &num2;

    printf("\nExpected Output :\n");
    //printf("\n %d is the maximum number. ",max);
    bigger(num1, num2, &max, text);

    return 0;
}

