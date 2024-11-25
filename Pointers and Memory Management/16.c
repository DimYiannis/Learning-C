#include <stdio.h>
#include <stdlib.h>

int function(int count, int *numbers);

int main()
{

  int count = 0;
  int numbers[10];
  int sum = 0;

  printf("\nInput the number of elements to store in the array (max 10) :");
  scanf("%d", &count);

  if (count > 10)
  {
    printf("You can only store up to 10 elements.\n");
    return 1; // Exit the program with an error code
  }

  printf("Input %d number of elements in the array :\n", count);

  for (int i = 0; i < count; i++)
  {
    printf("element - %d :", i+1);
    scanf("%d", &numbers[i]);
  }

  sum = function(count, numbers);

  printf("The sum of array is : %d", sum);

  return 0;
}

int function(int count, int *numbers)
{
  int sum = 0;
  for (int i = 0; i < count; i++)
  {
    sum += numbers[i];
  }
  return sum;
}