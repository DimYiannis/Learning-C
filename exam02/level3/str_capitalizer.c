/*
Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n.

Example:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>
*/

#include <unistd.h>
int		ft_str_is_numeric(char	*str);
int		ft_str_is_alpha(char	*str);
char	*ft_strupcase(char	*str);
char	*ft_strlowcase(char	*str);

char	*ft_strcapitalize(char *str)
{
	char	*p;

	p = str;
	while (*p != '\0')
	{
		while (ft_str_is_alpha(p) == 1 || ft_str_is_numeric(p) == 1)
		{
			if (ft_str_is_alpha(p) == 1)
			{
				ft_strupcase(p);
				p++;
			}
			else
				p++;
			while (ft_str_is_alpha(p) == 1)
			{
				ft_strlowcase(p);
				p++;
			}
		}
		p++;
	}
	return (str);
}

int main(int argc, char **argv)
{
    int i = 1;
    int j = 0;

    if (argc < 2)
        write(1, "\n", 1);
    while (i < argc)
    {
        j = 0;
        char *x = argv[i];
        ft_strcapitalize(x);
	    while (x[j] != '\0')
        {
            write(1, &x[j], 1);
            j++;
        }
        i++;
        write(1,"\n",1);
    }
	
}

int	ft_str_is_alpha(char *str)
{
	if ((*str > 64 && *str < 91) || (*str > 96 && *str < 123))
	{
		str++;
	}
	else
	{
		return (0);
	}
	return (1);
}

int	ft_str_is_numeric(char *str)
{
	if (*str > 47 && *str < 58)
	{
		str++;
	}
	else
	{
		return (0);
	}
	return (1);
}

char	*ft_strupcase(char *str)
{
	char	*p;

	p = str;
	if (*p > 96 && *p < 123)
	{
		*p = *p - 32;
		p++;
	}
	else
		p++;
	return (str);
}

char	*ft_strlowcase(char *str)
{
	char	*p;

	p = str;
	if (*p > 64 && *p < 91)
	{
		*p = *p + 32;
		p++;
	}
	else
		p++;
	return (str);
}