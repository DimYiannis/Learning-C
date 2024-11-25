#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Team {
    char name[50];
    int european_Trophies;
    char country[50];
};

int main() {

    struct Team team;

    printf("\nEnter your favorite team: ");
    scanf(" %s", team.name);
    printf("\n Enter the country of origin: ");
    scanf(" %s", team.country);
    printf("\n enter the number of european trophies this team has: ");
    scanf(" %d", &team.european_Trophies);

    // Declare a pointer to the structure
    struct Team *teamPtr;  

    // Assign the address of the structure variable to the pointer
    teamPtr = &team;  

    printf("\n team : %s", teamPtr->name);
    printf("\n country: %s", teamPtr->country);
    printf("\n cups: %d", teamPtr->european_Trophies);
    printf("\n team: %s", (*teamPtr).name );
    printf("\n country: %s", (*teamPtr).country );
    printf("\n cups: %d", (*teamPtr).european_Trophies);

}