#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    size_t          i;
    unsigned char   *arr1;

    i = 0;
    arr1 = ((unsigned char *) s);
    while (arr1[i] && i < n)
    {
        if (arr1[i] == c)
            return(&arr1[i]);
        i++;
    }
    return (NULL);
}