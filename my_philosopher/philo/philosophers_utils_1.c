/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:30:44 by fnochiza          #+#    #+#             */
/*   Updated: 2022/07/06 19:55:45 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atoi(char *s)
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

void	*ft_calloc(size_t size, size_t count)
{
	char			*s;
	size_t			total;
	size_t			i;

	if (count && SIZE_MAX / count < size)
		return (NULL);
	total = size * count;
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

void	print_log(int variable, t_philo p)
{
	int	x;

	pthread_mutex_lock(&p.table->print);
	x = p.id + 1;
	if (variable == 1)
		printf("%lld %i has taken a fork\n", ft_time(0) - p.table->s_time, x);
	if (variable == 2)
		printf("%lld %i is eating\n", ft_time(0) - p.table->s_time, x);
	if (variable == 3)
		printf("%lld %i is thinking\n", ft_time(0) - p.table->s_time, x);
	if (variable == 4)
		printf("%lld %i is sleeping\n", ft_time(0) - p.table->s_time, x);
	if (variable == 5)
		printf("%lld %i died\n", ft_time(0) - p.table->s_time, x);
	pthread_mutex_unlock(&p.table->print);
}

void	sleeping(long long t)
{
	long long	b;

	b = ft_time(0);
	while (ft_time(0) < (b + t))
	{
		usleep(10);
	}
}
