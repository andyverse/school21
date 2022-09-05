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

char *ft_strtrim(char const *s1, char const *set)
{
    int     i;
    int     j;
    char    *ss1;
    char    *sset;
    char    *str;

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

// FT_SPLIT ***************************************************

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
        if (str[i - 1] != c)
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

// FT_SPLIT ***************************************************************
// FT_ITOA ***************************************************************
static int size_int(char *s, int n, int *isneg)
{
    int i;
    int count;

    i = 1;
    count = 0;
    if (n < 0)
    {
        i++;
        *isneg = -1;
    }
    while ((n = n / 10) != 0)
        i++;
    s = malloc((i + 1) * sizeof(char));
    return(i);
}

static void xten(char *s, int n, int size, int isneg)
{
    int i;
    int mod;

    i = 1;
    while (i <= size)
    {
        if (i == size && isneg < 0)
        {
            s[0] = '-';
            break ;
        }
        mod = n % 10;
        s[size - i] = mod + 48;
        i++;
        n /= 10;
    }
        s[size] = '\0';
}

char *ft_itoa(int n)
{
    int size;
    int isneg;
    int *isn;
    char *str;

    if (n == -2147483648)
    {
        str = "-2147483648";
        return (str);
    }
    isneg = 1;
    isn = &isneg;
    size = size_int(str, n, isn);
    if (n < 0)
        n = n * (-1);
    xten(str, n, size, isneg);
    return (str);
}
// FT_ITOA ***************************************************************

// FT_STRMAPI ***************************************************************
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
// FT_STRMAPI ***************************************************************

// FT_STRITERI ***************************************************************
void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    int i;

    i = 0;
    if (s != NULL)
    {
        while(s[i])
            {
                f(i, &s[i]);
                i++;
            }
    }
}
// FT_STRITERI ***************************************************************

void ft_putchar_fd(char c, int fd)
{
    if (fd < 0)
        return ;
    write(fd, &c, 1);
}

void ft_putstr_fd(char *s, int fd)
{
    int i;

    i = 0;
    if (fd < 0 || s == NULL)
        return ;
    while (s[i])
    {
        ft_putchar_fd(s[i], fd);
        i++;
    }
}

void ft_putendl_fd(char *s, int fd)
{
    ft_putstr_fd(s, fd);
    write(fd, '\n', 1);
}

void ft_putnbr_fd(int n, int fd)
{
    int i;
    char num[10];

    i = 0;
    if (n < 0)
        ft_putchar_fd('-', fd);
    while (n != 0)
    {
        num[i] = n % 10 + '0';
        i++;
        n = n / 10;
    }
    i--;
    while (i >= 0)
    {
        ft_putchar_fd(num[i], fd);
        i--;
    }
}

int main()
{
    char s[] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse";
    char *str;
    int i = 0;
    char **res;
    char c = ' ';

    res = ft_split(s, c);
    while (res[i])
    {
        printf("%s\n", res[i]);
        i++;
    }
    printf("%s", str); 
}