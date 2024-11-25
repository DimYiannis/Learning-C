#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2) {
    
    int result;
    
    if (num1 > num2) {
        printf("first number is bigger than the second one");
    } else if (num2 > num1) {
        printf("first number is smaller than the second one");
    } else {
        printf("first number is equal to the second one");
    }
}

int main() {
    
    max(10, 10);
    
    return 0;
}