#include "libft.h"

static char **ft_free(char **res)
{
    unsigned int i;

    while (res[i])
    {
        free(res[i]);
        i++;
    }
    free(res);  
    return (NULL);
}

static char **sp_substr(char **res, char *s, unsigned int start, size_t len)
{
    int i;
    int j;
    char *str;

    len = len + start;
    j = 0;
    while (start < (len))
    {
        res[0][j] = s[start];
        j++;
        start++;
    }
    res[0][j] = '\0';
    return (&(res)[0]);
}

static char **add_s(char **res, char *str, char c)
{
    int i;
    int size;
    int j;
    int count;

    i = 1;
    j = 0;
    size = 0;
    count = 0;
    while (str[i - 1])
    {
        if (str[i - 1] != '*')
            size++;
        if ((str[i - 1] != c) && (str[i] == '\0' || str[i] == c))
        {
            if (!(res[count] = (char *) malloc (size * sizeof(char))))
                return (ft_free(res));
            sp_substr(&res[count], str, (i - size), size);
            count++;
            size = 0;
        }
        i++;
    }
    res[count] = NULL;
    return (res);
}

static int size_c(char *s, char c)
{
    int i;
    int size;
    int count;
    
    i = 1;
    size = 0;
    count = 0;
    while (s[i - 1])
    {
        if ((s[i - 1] != c) && (s[i] == '\0' || s[i] == c))
            count++;
        i++;
    }        
    return (count);
}

char **ft_split(char const *s, char c)
{
    int i;
    char *str;
    char **res;

    if (s == NULL)
        return (NULL);
    i = 0;
    str = (char *) s;
    res = (char **) malloc(size_c(str, c) * sizeof(char *));
    if (!res)
        return (NULL);
    return (add_s(res, str, c));
}