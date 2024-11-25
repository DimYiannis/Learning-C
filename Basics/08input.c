#include <stdio.h>
#include <stdlib.h>

int main() {

    int age;
    char name[20];
    char hobbies[50];
    printf("Please enter your name: ");

    scanf("%s", name);

    printf("%s if you may enter your age: ", name);

    scanf("%d", &age);
 
    // Consume the newline character left by scanf
    getchar();

    printf("Dear %s you are %d years old \n", name, age);
    printf("Now lets get to know each other, name a few hobbies of yours: ");
    fgets(hobbies, 50, stdin);
    printf("So here with us we have %s who is %d years old and loves to do %s", name, age, hobbies);

    return 0;
}