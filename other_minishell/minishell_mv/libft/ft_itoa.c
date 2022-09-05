#include "libft.h"

void	*malloc(size_t size);

static	int	ft_len(int n, int sign)
{
	int	len;

	len = 1 + sign;
	n = n / 10;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static	int	ft_sign_mark(int n)
{
	int	sign_mark;

	sign_mark = 1;
	if (n < 0)
		sign_mark = -1;
	return (sign_mark);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	int		sign_mark;
	int		c;
	char	*res;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = ft_len(n, sign);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (0);
	res[len--] = 0;
	if (n < 0)
		res[0] = '-';
	sign_mark = ft_sign_mark(n);
	while (len >= sign)
	{
		c = n % 10 * sign_mark;
		res[len--] = c + '0';
		n /= 10;
	}
	return (res);
}
