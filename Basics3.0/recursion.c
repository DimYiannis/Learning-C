#include <stdio.h>
unsigned int factorial(unsigned int x);

int main() {
    /* testing code */
    printf("0! = %i\n", factorial(0));
    printf("1! = %i\n", factorial(1));
    printf("2! = %i\n", factorial(2));
    printf("3! = %i\n", factorial(3));
    printf("4! = %i\n", factorial(4));
    printf("5! = %i\n", factorial(5));
}

/* define your function here (don't forget to declare it) */
unsigned int factorial(unsigned int x)
{
    if (x ==0 || x == 1)
    {
        return 1;
    }
    else if (x> 1)
    {
        return x * factorial(x-1);
    }
}

/*The recursive calls create a sequence of function calls, each contributing to the overall computation. As the recursion progresses, it goes deeper into the calls, and when it reaches the base case, it starts to unwind.

Here's a step-by-step breakdown of the process:

Call Chain:

factorial(3) calls factorial(2)
factorial(2) calls factorial(1)
factorial(1) is the base case and returns 1.
Unwinding:

The result from the base case (1) is used to calculate the result for the next level:
factorial(2) returns 2 * 1 (result from the base case) which is 2.
factorial(3) returns 3 * 2 (result from the previous level) which is 6.
So, the sequence of multiplication is built during the unwinding process. Each level of recursion contributes its part to the final result, and this is how you get the correct factorial value.*/