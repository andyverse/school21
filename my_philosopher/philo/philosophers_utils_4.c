/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:39:25 by fnochiza          #+#    #+#             */
/*   Updated: 2022/07/06 20:43:21 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	end(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->die);
	philo->table->end = 4;
	pthread_mutex_unlock(&philo->table->die);
}

int	check_min_eat(t_philo *p, int i, int *eat)
{
	if (p[i].num_of_eat == p->table->min_eat)
	{
		if (p[i].eat_flag == 0)
		{
			p[i].eat_flag = 1;
			(*eat)++;
		}
		if (*eat == p->table->count)
		{
			end(p);
			pthread_mutex_lock(&p->table->print);
			return (1);
		}
	}
	return (0);
}

int	monitoring(t_philo *p)
{
	int			i;

	i = -1;
	while (++i < p->table->count)
	{
		pthread_mutex_lock(&p->table->eating);
		if (p->table->tt_die < (ft_time(0) - p[i].last_eat) * 1000)
		{
			pthread_mutex_unlock(&p->table->eating);
			end(p);
			print_log(5, p[i]);
			pthread_mutex_lock(&p->table->print);
			return (1);
		}
		pthread_mutex_unlock(&p->table->eating);
		pthread_mutex_lock(&p->inc_eat);
		if (p->num_of_eat == p->table->min_eat)
		{
			end(p);
			pthread_mutex_lock(&p->table->print);
			return (1);
		}
		pthread_mutex_unlock(&p->inc_eat);
	}
	return (0);
}

void	*check_terms(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	while (1)
	{
		if (monitoring(philo) == 1)
			return (0);
		sleeping(10);
	}
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
