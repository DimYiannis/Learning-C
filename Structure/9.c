#include <stdio.h>
#include <stdlib.h>

struct car
{
    int id;
    char model[20];
    int rental;
};

void calculate(int days, struct car car1, struct car car2, struct car car3) {
    int price1 = days * car1.rental;
    int price2 = days * car2.rental;
    int price3 = days * car3.rental;

    printf("\n the price for renting car %s for %d days is: %d",car1.model, days,  price1 );
    printf("\n the price for renting car %s for %d days is: %d",car2.model, days,  price2 );
    printf("\n the price for renting car %s for %d days is: %d",car3.model, days,  price3 );

}

int main()
{
    struct car car1, car2, car3;
    int days;

    printf("\nhello input the details for the 1st car (id model rental price per day): ");
    scanf("%d %s %d", &car1.id, car1.model, &car1.rental);

    printf("\ninput the details for the 2nd car (id model rental price per day): ");
    scanf("%d %s %d", &car2.id, car2.model, &car2.rental);

    printf("\n input the details for the 3rd car (id model rental price per day): ");
    scanf("%d %s %d", &car3.id, car3.model, &car3.rental);

    printf("\nDays of rental: ");
    scanf("%d", &days);

    calculate(days, car1, car2, car3);

    return 0;
}