/* 7. Write a program in C to store n elements in an array and print the elements using a pointer.
Test Data :
Input the number of elements to store in the array :5
Input 5 number of elements in the array :
element - 0 : 5
element - 1 : 7
element - 2 : 2
element - 3 : 9
element - 4 : 8
Expected Output :

 The elements you entered are :                                                                               
 element - 0 : 5                                                                                              
 element - 1 : 7                                                                                              
 element - 2 : 2                                                                                              
 element - 3 : 9                                                                                              
 element - 4 : 8  */

#include <stdio.h>
#include <stdlib.h>



int main() {

    int nums[5];


    printf("\n Test Data");
    printf("\n Input the number of elements to store in the array :5 ");
    printf("\n Input 5 number of elements in the array : ");
    
    for (int i = 0; i<5; i++)
    {
        printf("\n element - %d : ", i);
        scanf("%d", &nums[i]); // & υποδεικνύει την μεταβλητει που επιθυμώ να δεχτει την νέα τιμή
    }
    
    printf("\n Expected Output :\n");
    printf("\n The elements you entered are :\n");

    for (int i = 0; i < 5; i++)
    {
        printf("\n element - %d : ", i);
        printf("%d", nums[i]);
    }
    
  

    return 0;
}

