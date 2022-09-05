#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
    int i;
    int k;

    i = 0;
    k = 0;
    while (s[i])
    {
        if (((char *)s)[i] == c)
            k = i;
        i++;
    }
    if (((char *)s)[i] == c)
            return ((char *) s + i);
    if (((char *)s)[k] == c)
        return ((char *) s + k);
    return (NULL);
}