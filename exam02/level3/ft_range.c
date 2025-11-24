#include <stdlib.h>

int *ft_range(int start, int end)
{
	int size;
	int *arr;
	int i;

	// compute size (number of elements including start and end)
	if (start <= end)
		size = end - start + 1;
	else
		size = start - end + 1;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);

	i = 0;
	if (start <= end)
	{
		while (start <= end)
			arr[i++] = start++;
	}
	else
	{
		while (start >= end)
			arr[i++] = start--;
	}
	return (arr);
}
