#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
    size_t i;
    size_t k;

    i = 0;
    k = 0;
    if (dstsize == 0)
        return (0);
    while (dst[i])
        i++;
    while ((src[k] != '\0') && (k <= (dstsize - 1)))
    {
        dst[i] = src[k++];
        i++;
    }
    dst[i] = '\0';
    return (i);
}