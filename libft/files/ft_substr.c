#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    int i;
    char *str;

    if (s == NULL)
        return (NULL);
    if (start > ft_strlen((char *)s))
        return (NULL);
    if ((start + len) > ft_strlen((char *)s))
        str = malloc ((ft_strlen((char *)s) - start) * sizeof(char));
    else
        str = malloc (len * sizeof(char));
    if (str == NULL)
        return (NULL);
    i = 0;
    ft_strlcpy(str, &((char *)s)[start], len);
    return (str);
}