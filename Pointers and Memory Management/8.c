/*8. Write a program in C to print all permutations of a given string using pointers.
Expected Output :

The permutations of the string are :                                                                         
abcd  abdc  acbd  acdb  adcb  adbc  bacd  badc  bcad  bcda  bdca  bdac  cbad  cbda  cabd  cadb  cdab  cdba  db
ca  dbac  dcba  dcab  dacb  dabc*/
#include <stdio.h>
#include <stdlib.h>



int main() {
    
    char text[] = "abcd";

    for (int i=0; i<5;i++) {
        printf("%c", text[i]);
    }
    
    return 0;
}