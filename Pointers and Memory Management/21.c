/*21. Write a program in C to print all the alphabets using a pointer.
Expected Output :

The Alphabets are :
 A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *ptr;
    char alphabet[27];
    int x;

    ptr = alphabet;

    // Storing alphabets in the array using pointer arithmetic
    for (x = 0; x < 26; x++)
    {
        *ptr = x + 'A'; // Assigning ASCII values of alphabets to the array through the pointer
        ptr++;          // Moving the pointer to the next memory location
    }

    ptr =alphabet;

    int n = strlen(alphabet); // Get the length of the string

    for (int i = 0; i < n; i++)
    {
        printf("%c", *ptr);
        ptr++;
    }

    return 0;
}