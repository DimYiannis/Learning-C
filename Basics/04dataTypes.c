#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Include the string.h header

int main() {

    int age = 40;
    double gpa = 3.7;
    char grade = 'a';
    char phrase[] = "hello there";

    printf("%s \n", phrase);

    // Change the value of 'phrase'
    // Note: You can't redeclare the array, just assign a new value
    // to the existing array
    strcpy(phrase, "new phrase");

    printf("%s \n", phrase);



    return 0;
}