#include <stdio.h>
#include <stdlib.h>


struct date {
    int day;
    int month;
    int year;
};

void readdate(struct date *date) {
    printf("\nEnter year ");
    scanf("%d", &(*date).year );
    printf("Enter month: ");
    scanf("%d", &date->month);
    printf("Enter your day: ");
    scanf("%d", &date->day);
}

void datediff(struct date date1, struct date date2) {
    int yeardiff = date1.year-date2.year;
    int monthdiff = date1.month - date2.month;
    int daydiff = date1.day - date2.day;

    int diff = abs(yeardiff * 365 + monthdiff * 30 + daydiff);

    
    printf("there is a difference of %d days between the two dates", diff); 
}

int main() {

    struct date date1, date2;

    readdate(&date1);
    readdate(&date2);

    datediff(date1,date2);
    
}