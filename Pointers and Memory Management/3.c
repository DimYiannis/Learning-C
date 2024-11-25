/*3. Write a program in C to demonstrate the use of the &(address of) and *(value at address) operators.
Expected Output :

Pointer : Demonstrate the use of & and * operator :                                                          
--------------------------------------------------------                                                      
 m = 300                                                                                                      
 fx = 300.600006                                                                                              
 cht = z                                                                                                      
                                                                                                              
 Using & operator :                                                                                           
-----------------------                                                                                       
 address of m = 0x7ffda2eeeec8                                                                                
 address of fx = 0x7ffda2eeeecc                                                                               
 address of cht = 0x7ffda2eeeec7                                                                              
                                                                                                              
 Using & and * operator :                                                                                     
-----------------------------                                                                                 
 value at address of m = 300                                                                                  
 value at address of fx = 300.600006                                                                          
 value at address of cht = z                      

Using only pointer variable :                                                                                
----------------------------------                                                                            
 address of m = 0x7ffda2eeeec8                                                                                
 address of fx = 0x7ffda2eeeecc                                                                               
 address of cht = 0x7ffda2eeeec7                                                                              
                                                                                                              
 Using only pointer operator :                                                                                
----------------------------------                                                                            
 value at address of m = 300                                                                                  
 value at address of fx= 300.600006                                                                           
 value at address of cht= z*/

 #include <stdio.h>
 #include <stdlib.h>

 void address(int m, float fx, char cht[]) {

   printf("address of m =%p \naddress of fx =%p \naddress of cht =%p", &m ,&fx, &cht);

}

void value(int m, float fx, char cht[]) {

   printf("value at address of m =%d \n value at address of fx =%f \n value at address of cht =%s", m ,fx, cht);

}

 int main() {

    int m = 300;
    float fx = 300.600006 ;
    char cht[] = "z"; 

    printf("\nPointer : Demonstrate the use of & and * operator :");
    printf("\n--------------------------------------------------------");
    printf("\n m = %d\n fx = %f\n cht= %s", m , fx, cht);
    printf("\n ");
    printf("\n Using & operator : ");
    printf("\n--------------------------------------------------------\n");
    address(m,fx,cht);
    printf("\n Using & and * operator : ");
    printf("\n--------------------------------------------------------\n");
    value(m,fx,cht);
    printf("\n Using only pointer variable : ");
    printf("\n--------------------------------------------------------\n");
    address(m,fx,cht);
    printf("\n  Using only pointer operator :");
    printf("\n--------------------------------------------------------\n");
    value(m,fx,cht);

    return 0;
 }