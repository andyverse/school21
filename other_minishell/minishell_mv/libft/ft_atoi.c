#include "libft.h"

int	ft_atoi(const char *s)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	sign = 1;
	while (s[i] && ((s[i] == 32) || ((s[i] > 8) && (s[i] < 14))))
		i++;
	if (s[i] == 45)
	{
		sign = -1;
		i++;
	}
	else
		if (s[i] == 43)
			i++;
	res = 0;
	while ((s[i] > 47) && (s[i] < 58))
		res = (s[i++] - 48) + res * 10;
	return (res * sign);
}
