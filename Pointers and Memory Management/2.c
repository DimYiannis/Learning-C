/*2. Write a program in C to demonstrate how to handle pointers in a program.
Expected Output :

Address of m : 0x7ffcc3ad291c
 Value of m : 29                                                                                              
                                                                                                              
 Now ab is assigned with the address of m.                                                                    
 Address of pointer ab : 0x7ffcc3ad291c                                                                       
 Content of pointer ab : 29                                                                                   
                                                                                                              
 The value of m assigned to 34 now.                                                                           
 Address of pointer ab : 0x7ffcc3ad291c                                                                       
 Content of pointer ab : 34                                                                                   
                                                                                                              
 The pointer variable ab is assigned with the value 7 now.                                                    
 Address of m : 0x7ffcc3ad291c                                                                                
 Value of m : 7 
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int m;
    int * pM = &m;
    int * ab = pM;
    m=29;

    printf("\n Address of m: %p", &m);
    printf("\n Value of m: %d", m);
    printf("\n");
    printf("\n Now ab is assigned with the address of m.");
    printf("\n Address of pointer ab :%p", ab);
    printf("\n Content of pointer ab :%d", *ab);
    printf("\n");
    m = 34;
    printf("\n Address of pointer ab : %p", ab);
    printf("\n Content of pointer ab:%d", *ab);
    printf("\n");
    *ab=7;
    printf("\nThe pointer variable ab is assigned with the value 7 now");
    printf("\nAddress of m :%p", pM);
    printf("\nValue of m :%d", m);




    return 0;
}

