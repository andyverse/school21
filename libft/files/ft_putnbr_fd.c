#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
    int i;
    char num[10];

    i = 0;
    if (n < 0)
        ft_putchar_fd('-', fd);
    while (n != 0)
    {
        num[i] = n % 10 + '0';
        i++;
        n = n / 10;
    }
    i--;
    while (i >= 0)
    {
        ft_putchar_fd(num[i], fd);
        i--;
    }
}