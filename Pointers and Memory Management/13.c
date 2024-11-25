#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


void check(char* x);

int main() {

    char input[100];

    printf("Input a string: string \n");
    scanf("%99s", input);

    check(input);

}

void check(char* x) {

    int len = strlen(x);
    char y[len + 1];
    int vowels =0;
    int consonants=0;

    for (int i=0; i< len; i++) {
        y[i] = tolower(x[i]);
    }

    y[len] = '\0';

    for (int i=0; i<len; i++) {
        if ( y[i] == 'a' || y[i]== 'e' || y[i]=='i' ||y[i]== 'o' || y[i]== 'u') {
            vowels++;
        }
        else if (isalpha(y[i])) {
            consonants++;
        }
    }

    printf("\n Number of vowels : %d ", vowels);
    printf("\n Number of consonants : %d ", consonants);

}