#include "libft.h"

char *ft_strdup(const char *str)
{
    int     i;
    char    *twice;

    i = 0;
    while (str[i])
        i++;
    twice = malloc((i + 1) * sizeof(char));
    if (twice == NULL)
        return (NULL);
    ft_memcpy(twice, str, i);
    twice[i] = '\0';
    return(twice);
}