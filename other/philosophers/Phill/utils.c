/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:20:03 by chfederi          #+#    #+#             */
/*   Updated: 2022/05/17 20:20:06 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	ft_checkarg(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
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

long long	ft_time(long long l)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	l = 1;
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

int	ft_check_o(t_args *args)
{
	if (args->tt_sleep <= 0 || args->tt_die <= 0 || args->n <= 0
		|| args->tt_eat <= 0 || args->tt_eat <= 0)
	{
		if (args->forks)
			free(args->forks);
		if (args->t_id)
			free(args->t_id);
		write(2, "Error: wrong argument\n", 22);
		return (1);
	}
	return (0);
}
