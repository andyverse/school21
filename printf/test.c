#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

static int	ft_white(const char c)
{
	if (c == '\n' || c == '\t' || c == '\r' \
	|| c == '\v' || c == '\f' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;
	int	count;

	i = 0;
	res = 0;
	sign = 1;
	count = 0;
	printf("lenght: %lld\n", ft_strlen(str));
	while (ft_white(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - 48);
		count++;
	}
	return (res * sign);
}

int	main(void)
{
	char	*c;

	c = "99999999999999999999";
	printf("%d\n", atoi(c));
	printf("%d\n", ft_atoi(c));
	printf("---\n");
}
