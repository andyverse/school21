#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char    *res_s;
    int     size1;
    int     size2;
    if (s1 == NULL && s2 == NULL)
        return (NULL);
    size1 = ft_strlen((char *) s1);
    size2 = ft_strlen((char *) s2);
    res_s = malloc ((size1 + size2) * sizeof(char));
    if (res_s == NULL)
        return (NULL);
    ft_strlcpy(res_s, (char *) s1, size1);
    ft_strlcat(res_s, (char *) s2, size2);
    return (res_s);
}