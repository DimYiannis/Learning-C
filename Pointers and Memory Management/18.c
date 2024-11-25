#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    char name[50];
    char address[50];
};

int main()
{
    struct Person person;

    strcpy(person.name, "John Alter");
    strcpy(person.address, " court street");

    struct Person *personPtr;

    personPtr = &person;


    //In C, when you're using a pointer to a structure, you can indeed 
    //use the dereference operator (*) to access the structure, 
    //but it is more common and convenient to use the arrow operator 
    //(->). However, you can achieve the same result with the
    // dereference operator.
    printf("%s from %s\n", (*personPtr).name, (*personPtr).address);
    printf("%s from %s", personPtr->name, personPtr->address);

    return 0;
}