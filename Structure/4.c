#include <stdio.h>
#include <stdlib.h>

#define PI 3.141592653589793


struct circle {
    double radius;
    double area;
    double perimeter;
};


int main() {

    struct circle circle1, circle2;


    printf("\nenter the radius of the 1st circle: ");
    scanf("%lf", &circle1.radius);
    printf("\nenter the radius of the 2nd circle: ");
    scanf("%lf", &circle2.radius);

    circle1.area= 2*PI*circle1.radius*circle1.radius;
    circle1.perimeter= 2*PI*circle1.radius;

    circle2.area= 2*PI*circle2.radius*circle2.radius;
    circle2.perimeter= 2*PI*circle2.radius;

    printf("the area af circle 1 is: %.2lf and with perimeter %.2lf", circle1.area, circle1.perimeter);
    printf("the area af circle 2 is: %.2lf and with perimeter %.2lf", circle2.area, circle2.perimeter);




}