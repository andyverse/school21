#include "libft.h"

void ft_putstr_fd(char *s, int fd)
{
    int i;

    i = 0;
    if (fd < 0 || s == NULL)
        return ;
    while (s[i])
    {
        ft_putchar_fd(s[i], fd);
        i++;
    }
}