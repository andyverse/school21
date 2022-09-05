#include "libft.h"

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