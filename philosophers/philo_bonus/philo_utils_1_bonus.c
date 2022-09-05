/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 04:33:31 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/30 04:58:53 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_zero(t_table *table)
{
	if (table->tt_sleep <= 0 || table->tt_die <= 0 || table->count <= 0
		|| table->tt_eat <= 0 || table->tt_eat <= 0)
	{
		free(table);
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
