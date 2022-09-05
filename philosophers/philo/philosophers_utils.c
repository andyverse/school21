/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 05:49:10 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/30 02:26:55 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_digit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	is_numbers(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (is_digit(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

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

void	*ft_calloc(size_t n, size_t size)
{
	char			*s;
	size_t			total;
	size_t			i;

	if (size && SIZE_MAX / size < n)
		return (NULL);
	total = n * size;
	s = malloc(total);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (total--)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}
