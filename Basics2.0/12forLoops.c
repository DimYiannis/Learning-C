#include <stdio.h>
#include <stdlib.h>

int main()
{

    int secretNumber = 5;
    int guess;
    int guessCount;

    for (guessCount = 0; guessCount <= 2; guessCount++)
    {
        printf("Enter a number: ");
        scanf("%d", &guess);

        if (secretNumber == guess)
        {
            printf("You win!");
            break;
        }
        else
        {
            printf("Incorrect guess. Try again.\n");
        }
    }
    if (guessCount == 3)
    {
        printf("You lost! The correct number was %d.\n", secretNumber);
    }

    return 0;
}
