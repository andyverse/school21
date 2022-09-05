#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while(s1[i] && i < n)
    {
        if(s1[i] != s2[i])
        {
            if (s1[i] > s2[i])
                return (1);
            else
                return (-1);
        }
        i++;
    }
    if (s2[i] != '\0')
        return (-1);
    return (0);
}