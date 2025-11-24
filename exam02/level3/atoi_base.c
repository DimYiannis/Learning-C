#include <stdio.h>

int	ft_atoi_base(const char *str, int base)
{
	int res = 0;
	int sign = 1;
	int i = 0;
	int digit;

	if (base < 2 || base > 16)
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}

	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit = str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			digit = str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			digit = str[i] - 'a' + 10;
		else
			break;

		if (digit >= base)
			break; // character not allowed in this base

		res = res * base + digit;
		i++;
	}

	return (res * sign);
}
