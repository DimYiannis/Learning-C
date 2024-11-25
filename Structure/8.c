#include <stdio.h>
#include <stdlib.h>

struct complex
{
    float real;
    float imaginary;
};

struct complex addition(struct complex comp1, struct complex comp2)
{
    struct complex result;
    result.real = comp1.real + comp2.real;
    result.imaginary = comp1.imaginary + comp2.imaginary;
    return result;
}

struct complex multiplication(struct complex comp1, struct complex comp2)
{
    struct complex result;
    result.real = (comp1.real * comp2.real) - (comp1.imaginary * comp2.imaginary);
    result.imaginary = (comp1.real * comp2.imaginary) + (comp1.imaginary * comp2.real);
    return result;
}

void displayComplex(struct complex num)
{
    printf("%.2f + %.2fi\n", num.real, num.imaginary);
}

int main()
{
    struct complex comp1, comp2, sumresult, productresult;

    printf("\n input details for complex number 1 (real, imaginary): ");
    scanf("%f %f", &comp1.real, &comp1.imaginary);

    printf("\n input details for complex number 2 (real, imaginary): ");
    scanf("%f %f", &comp2.real, &comp2.imaginary);

    sumresult = addition(comp1, comp2) ;

    productresult = multiplication(comp1 , comp2);

    printf("\nSum of Complex Numbers:\n");
    displayComplex(sumresult);

    printf("\nProduct of Complex Numbers:\n");
    displayComplex(productresult);

    return 0;
}