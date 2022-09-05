#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    int i;
    char  *str;

    if (!s || !f)
        return (NULL);
    i = 0;
    while (s[i])
        i++;
    if(!(str = malloc((i + 1) * sizeof(char))))
        return (NULL);
    i = 0;
    while (str[i])
    {
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return (str);
}