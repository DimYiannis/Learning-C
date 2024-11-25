#include <stdio.h>
#include <stdlib.h>

struct Book
{
    char title[50];
    char author[50];
    double price;
};

int main()
{

    struct Book book1, book2, book3;

    printf("\n enter book's title: ");
    scanf("%s", book1.title);
    printf("\n enter book's author: ");
    scanf("%s", book1.author);
    printf("\n enter book's price: ");
    scanf("%lf", &book1.price );

    printf("\n enter book's title: ");
    scanf("%s", book2.title);
    printf("\n enter book's author: ");
    scanf("%s", book2.author);
    printf("\n enter book's price: ");
    scanf("%lf", &book2.price );

    printf("\n enter book's title: ");
    scanf("%s", book3.title);
    printf("\n enter book's author: ");
    scanf("%s", book3.author);
    printf("\n enter book's price: ");
    scanf("%lf", &book3.price );

    struct Book exp;
    if (book1.price>=book2.price && book1.price>=book3.price) {
        exp = book1;
    }
    else if (book2.price>=book1.price && book2.price>=book3.price) {
        exp = book2;
    }
    else {
        exp = book3;
    }

    struct Book aff;
    if (book1.price<=book2.price && book1.price<=book3.price) {
        aff = book1;
    }
    else if (book2.price<=book1.price && book2.price<=book3.price) {
        aff = book2;
    }
    else {
        aff = book3;
    }


   printf("them most expensive book is: %s", exp.title );
   printf("price: %.2lf", exp.price );
   printf("author: %s", exp.author );
   printf("them most affordable book is: %s", aff.title );
   printf("price: %.2lf", aff.price );
   printf("author: %s", aff.author );

}