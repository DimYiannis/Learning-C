#include <stdio.h>
#include <stdlib.h>

int main()
{

    int secretNumber = 5;
    int guess;
    int guessCount = 0;

    while (guess != secretNumber && guessCount<=2)
    {
        printf("Enter a number: ");
        scanf("%d", &guess);
        guessCount++;
    }

    if (guess == secretNumber)
    {
        printf("You Win!");
    }
    else
    {
        printf("You lost!");
    }

    return 0;
}
