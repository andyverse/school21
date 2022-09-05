#include "minishell.h"

static	int	ft_numlen(unsigned num)
{
	int	len;

	len = 1;
	while (num / 10 > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static	char	*ft_num_str(char *str, int len, unsigned num, int sign)
{
	str[len--] = 0;
	str[len--] = num % 10 + '0';
	while (num / 10 > 0)
	{
		num = num / 10;
		str[len--] = num % 10 + '0';
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char	*ft_itoa_minishell(int n, t_prm *prm)
{
	char		*str;
	int			sign;
	int			len;
	unsigned	num;

	sign = 0;
	num = n;
	if (n < 0)
	{
		sign = 1;
		num = -n;
	}
	len = ft_numlen(num) + sign;
	str = malloc((len + 1) * sizeof(*str));
	if (str == NULL)
		ft_err_exit(12, "malloc", prm);
	return (ft_num_str(str, len, num, sign));
}

void	ft_bkslash2(char *str, int *i)
{
	int		j;

	j = *i;
	j++;
	while (str[j])
	{
		if (str[j] == '\"')
		{
			*i = j + 1;
			return ;
		}
		else
			j++;
	}
	(*i)++;
}

void	ft_bkslash1(char *str, int *i)
{
	int		j;

	j = *i;
	j++;
	while (str[j])
	{
		if (str[j] == '\'')
		{
			*i = j + 1;
			return ;
		}
		else
			j++;
	}
	(*i)++;
}
