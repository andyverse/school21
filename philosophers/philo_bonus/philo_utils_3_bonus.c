/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 04:36:17 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/30 04:58:42 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	ft_print(int v, t_philo p, t_table *table)
{
	int	x;

	sem_wait(table->pr);
	x = p.id + 1;
	if (v == 1)
		printf("%lld %i has taken a fork\n", ft_time(0) - p.table->s_time, x);
	if (v == 2)
		printf("%lld %i is eating\n", ft_time(0) - p.table->s_time, x);
	if (v == 3)
		printf("%lld %i is thinking\n", ft_time(0) - p.table->s_time, x);
	if (v == 4)
		printf("%lld %i is sleeping\n", ft_time(0) - p.table->s_time, x);
	if (v == 5)
		printf("%lld %i died\n", ft_time(0) - p.table->s_time, x);
	sem_post(table->pr);
}

void	ft_sleep(long long t)
{
	long long	b;

	b = ft_time(0);
	while (ft_time(0) < (b + t))
	{
		usleep(10);
	}
}

void	destroy(t_table *table, t_philo *philo)
{
	sem_unlink("forks");
	sem_unlink("pr");
	sem_unlink("check");
	sem_close(table->forks);
	sem_close(table->pr);
	sem_close(table->check);
	free(philo);
	free(table);
	exit(0);
}
