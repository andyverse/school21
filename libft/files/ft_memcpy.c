#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    size_t             i;
    unsigned char   *dest1;
    unsigned char   *sourse1;

    if (dst == NULL || src == NULL)
        return (NULL);
    i = 0;
    dest1 = ((unsigned char *) dst);
    sourse1 = ((unsigned char *) src);
    while (i < n)
    {
        dest1[i] = sourse1[i];
        i++;
    }
    return (dst);
    }