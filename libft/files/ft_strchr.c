#include "libft.h"

char *ft_strchr (const char *s, int c)
{
    int i;

    i = 0;
    while (s[i])
    {
        if (((char *)s)[i] == c)
            return ((char *) s + i);
        i++;
    }
    if (((char *)s)[i] == c)
            return ((char *) s + i);
    return (NULL);
}