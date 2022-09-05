#include "ft_lib.h"

int ft_isalpha(int n)
{
    if((n >= 65 && n <= 90) || (n >= 97 && n <= 122))
        return (1);
    return (0);
}

int ft_isdigit(int n)
{

    if(n >= 48 && n <=  57)
        return (1);
    return (0);
}

int ft_isalnum(int n)
{
    if((n >= 48 && n <=  57) || \
        (n >= 65 && n <= 90) || (n >= 97 && n <= 122))
        return (1);
    return (0);
}

int     ft_isascii(int n)
{
    if(n >= 0 && n <=  127)
        return (1);
    return (0);
}

int ft_isprint(int n)
{
    if(n >= 32 && n <=  126)
        return (1);
    return (0);
}

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
        i++;

    return (i);
}

void *ft_memset(void *str, char c, int n)
{
        int i;

        i = 0;
        while (i < n)
        {
            ((unsigned char *) str)[i] = c;
            i++;
        }
    return (str);
}

void *ft_bzero(void *str, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        ((unsigned char *) str)[i] = 0;
        i++;
    }
    return (str);
}

void *ft_memcpy(void *dest, const void *sourse, int n)
{
    int             i;
    unsigned char   *dest1;
    unsigned char   *sourse1;

    if (dest == NULL || sourse == NULL)
        return (NULL);
    i = 0;
    dest1 = ((unsigned char *) dest);
    sourse1 = ((unsigned char *) sourse);
    while (i < n)
    {
        dest1[i] = sourse1[i];
        i++;
    }
    return (dest);
}

void *ft_memmove(void *dest, const void *source, int n)
{
    int             i;
    int             k;
    unsigned char   *dest1;
    unsigned char   *source1;

    if (dest == NULL && source == NULL)
        return (NULL);
    i = 1;
    dest1 = ((unsigned char *) dest);
    source1 = ((unsigned char *) source);
    if (source1 < dest1)
	{
		while (i <= n)
		{
			dest1[n - i] = source1[n - i];
			i++;
		}
	}
    else
        ft_memcpy(dest1, source1, n);
    return (dest);
}

unsigned int ft_strlcpy(char *dest, char *source, int n)
{
    int i;

    i = 0;
    if (n == 0)
        return (0);
    while ((source[i] != '\0') && (i <= (n-1)))
    {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
    return (i);
}

unsigned int ft_strlcat(char *dest, char *source, int n)
{
    int i;
    int k;

    i = 0;
    k = 0;
    if (n == 0)
        return (0);
    while (dest[i])
        i++;
    while ((source[k] != '\0') && (k <= (n-1)))
    {
        dest[i] = source[k++];
        i++;
    }
    dest[i] = '\0';
    return (i);
}

int ft_toupper(int n)
{
    if (n >= 97 && n <= 122)
        return(n - 32);
    return(n);
}

int ft_tolower(int n)
{
    if (n >= 65 && n <= 90)
        return(n + 32);
    return(n);
}

char *ft_strchr (const char *str, int c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (((char *)str)[i] == c)
            return ((char *) str + i);
        i++;
    }
    if (((char *)str)[i] == c)
            return ((char *) str + i);
    return (NULL);
}

char *ft_strrchr (const char *str, int c)
{
    int i;
    int k;

    i = 0;
    k = 0;
    while (str[i])
    {
        if (((char *)str)[i] == c)
            k = i;
        i++;
    }
    if (((char *)str)[i] == c)
            return ((char *) str + i);
    if (((char *)str)[k] == c)
        return ((char *) str + k);
    return (NULL);
}

int ft_strncmp(char *str1, char *str2, int n)
{
    int i;

    i = 0;
    while(str1[i] && i < n)
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

void *ft_memchr(const void *arr, int c, size_t n)
{
    int             i;
    unsigned char   *arr1;

    i = 0;
    arr1 = ((unsigned char *) arr);
    while (arr1[i] && i < n)
    {
        if (arr1[i] == c)
            return(&arr1[i]);
        i++;
    }
    return (NULL);
}

int ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
    int             i;
    unsigned char   *str1;
    unsigned char   *str2;

    if (arr1 == NULL && arr2 == NULL)
        return (0);
    i = 0;
    str1 = ((unsigned char *) arr1);
    str2 = ((unsigned char *) arr2);
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

char *ft_strnstr(const char *strB, const char *strA, int n)
{
    int     i;
    int     j;
    char    *str1;
    char    *str2;

    i = 0;
    str1 = ((char *) strA);
    str2 = ((char *) strB);
    if (str1[0] == '\0')
        return ((char *)strB);

    while(strB[i] && i < n)
    {
        if (strB[i] == strA[0])
        {
            j = 0;
            while((i + j) < n)
            {
                if (strB[i + j] == strA[j])
                {
                    j++;
                    continue ;
                }
                else
                    break;
            }
            if (strA[j] == '\0')
                return ((char *)(&strB[i]));
        }
        i++;
    }
    return (NULL);
}

int ft_atoi (const char *s)
{
    int i;
    int sp;
    int res;
    int sign;
    int c;

    i = 0;
    c = 0;
    sign = 1;
    res = 0;
    while (s[i])
    {
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] == 32 && res == 0 && c == 0))
            res = res * 10 + (sp = (s[i] == 32) ? 0 : s[i] - 48);
        else if ((s[i] == '-') && (c++ == 0))
            sign = -1;
        else if ((s[i++] == '+') && (c++ == 0))
            continue ;
        else
            return (res * sign);
        i++;
    }
    return (res * sign);
}


void *ft_calloc(size_t num, size_t size)
{
    int i;
    char *str;

    i = 0;
    str = malloc(num * sizeof(size));
    while(num--)
        *str++ = 0;
    return (&str[0]);
}

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
        printf ("%d\n", i);
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


int main(void)
{
    int n = -43534;
    //int n = 0;
    char c = '*';
    char str[] = "**123*1*12**432***";
    //char str[] = "     -0";
    //char *str;
    //int str[] = {1, 2, 3, 4, 5};
    //char *str = NULL;
    //printf("%d\n", sizeof(str));
    //memset(str, '*', n);
    //printf("mem %s\n", str);
    char str1[] = "     -0";
    char *str2;
    ft_itoa(n);
    printf ("%d", n);
    //printf("\n%d", size_c(str, c));
}
