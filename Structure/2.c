#include <stdio.h>
#include <stdlib.h>

struct Time {
    int hours;
    int min;
    int sec;
};

int main() {

    struct Time time1, time2;

    printf("\n enter the 1st hour: ");
    scanf("%d %d %d",&time1.hours, &time1.min, &time1.sec );

    printf("\n enter the 2nd hour: ");
    scanf("%d %d %d",&time2.hours, &time2.min, &time2.sec );

    printf("\nYou entered the 1st time: %d hours, %d minutes, %d seconds\n", time1.hours, time1.min, time1.sec);
    printf("\nYou entered the 2nd time: %d hours, %d minutes, %d seconds\n", time2.hours, time2.min, time2.sec);

}