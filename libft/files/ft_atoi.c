#include "libft.h"

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
	int	s;
	int	res;
	int	count;

	i = 0;
	res = 0;
	s = 1;
	count = 0;
	while (ft_white(str[i]))
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - 48);
		count++;
	}
	if ((count > 19 || (i >= 1 && str[i - 1] == '9' && count == 19)) && s == 1)
		return (-1);
	if ((count > 19 || (i >= 1 && str[i - 1] == '9' && count == 19)) && s == -1)
		return (0);
	return (res * s);
}