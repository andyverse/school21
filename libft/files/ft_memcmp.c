#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    size_t          i;
    unsigned char   *str1;
    unsigned char   *str2;

    if (s1 == NULL && s2 == NULL)
        return (0);
    i = 0;
    str1 = ((unsigned char *) s1);
    str2 = ((unsigned char *) s2);
    while (i < n)
    {
        if(str1[i] != str2[i])
        {
            if (str1[i] > str2[i])
                return (1);
            else
                return (-1);
        }
        i++;
    }
    if (str2[i] != '\0')
        return (-1);
    return (0);
}