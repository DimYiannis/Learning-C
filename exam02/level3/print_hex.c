#include <unistd.h>

void    ft_puthex(unsigned int n, int uppercase)
{
    char    hex[16];
    char    c;
    int     i;

    // fill hex table with if statements
    i = 0;
    while (i < 16)
    {
        if (i < 10)
            hex[i] = '0' + i;
        else
        {
            if (uppercase)
                hex[i] = 'A' + (i - 10);
            else
                hex[i] = 'a' + (i - 10);
        }
        i++;
    }

    // recursive printing
    if (n >= 16)
        ft_puthex(n / 16, uppercase);

    c = hex[n % 16];
    write(1, &c, 1);
}
