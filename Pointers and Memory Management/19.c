#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Person
{
    char name[50];
    char address[50];
};

int main()
{
    union Person person, *personPtr;

    strcpy(person.name, "Jhon Mc");

    personPtr = &person;

    printf("%s  %s\n", (*personPtr).name, personPtr->name );

    strcpy(person.address, " court street");
    
    printf("%s from %s\n", (*personPtr).name, (*personPtr).address);
    printf("%s from %s", personPtr->name, personPtr->address);

    return 0;
}