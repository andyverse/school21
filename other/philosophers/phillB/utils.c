/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 22:35:09 by chfederi          #+#    #+#             */
/*   Updated: 2022/06/13 22:35:13 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillob.h"

void	ft_check_o(t_args *args)
{
	if (args->tt_sleep <= 0 || args->tt_die <= 0 || args->n <= 0
		|| args->tt_eat <= 0 || args->tt_eat <= 0)
	{
		free(args);
		write(2, "Error: wrong argument\n", 22);
		exit(3);
	}
}

int	ft_isdigit(char *arg)
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

long long	ft_time(long long l)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	l = 1;
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
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

long	ctoi(char *s)
{
	long	i;
	int		x;
	int		a;

	x = 0;
	i = 0;
	a = 1;
	if (s[0] == '-')
	{
		a = -1;
		x++;
	}
	if (s[0] == '+')
		x++;
	while (s[x])
	{
		i = i * 10;
		i += s[x++] - '0';
	}
	return (i * a);
}
