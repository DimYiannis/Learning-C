#include <stdio.h>
#include <math.h>


int main() {
    
    const double PI = 3.14159;
    double radius;
    double circumference;
    double area;

    printf("\n Enter radius of a circle: ");
    scanf("%lf", &radius);

    circumference = 2 * PI * radius;

    printf("Circumference: %lf", circumference);

    area = PI * radius * radius;

    printf("\nArea: %lf", area);


    return 0;
}