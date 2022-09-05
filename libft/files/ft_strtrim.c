#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
    int     i;
    int     j;
    char    *ss1;
    char    *sset;
    char    *str;

    i = 0;
    j = ft_strlen(ss1);
    ss1 = (char *) s1;
    sset = (char *) set;
    while (ss1[i] && ft_strchr(sset, ss1[i]))
        i++;
    while (j != 0 && ft_strchr(sset, ss1[j]))
        j--;
    str = ft_substr(ss1, i, (j - i + 1));
    return (str);
}