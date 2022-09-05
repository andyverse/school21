#include "libft.h"

void *ft_calloc(size_t num, size_t size)
{
    int i;
    char *str;

    i = 0;
    str = malloc(num * sizeof(size));
    while(num--)
        *str++ = 0;
    return (&str[0]);
}