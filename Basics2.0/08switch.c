#include <stdio.h>
#include <stdlib.h>


int main() {
    
 char grade;
 printf("enter student's grade: ");
 scanf(" %c", &grade);

 switch(grade) {
    case 'A' :
    printf("you did great!");
    break;
    case 'B' :
    printf("you did alright!");
    break;
    case 'C' :
    printf("you did poorly!");
    break;
    case 'D' :
    printf("you did bad!");
    break;
    case 'F' :
    printf("you failed the test!");
    break;
    default:
        printf("Invalid grade");
 }

    return 0;
}

