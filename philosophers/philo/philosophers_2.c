/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 02:27:59 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/30 03:49:50 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	ft_time(long long l)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	l = 1;
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

t_philo	*philo_init(t_table *table)
{
	t_philo		*philo;
	int			i;

	i = -1;
	philo = ft_calloc(sizeof (t_philo), table->count);
	if (!philo)
		return (NULL);
	while (++i < table->count)
	{
		philo[i].id = i;
		philo[i].la_eat = table->s_time;
		philo[i].table = table;
		philo[i].l_f = i;
		philo[i].r_f = i + 1;
		philo[i].ea = 0;
		philo[i].forks = table->forks;
		if (table->count == 1)
			philo[i].r_f = 0;
		if (i == table->count - 1)
			philo_init_2(philo, i);
		if (pthread_mutex_init(&philo[i].eating, NULL) != 0)
			return (philo_delete(philo));
	}
	return (philo);
}

void	philo_init_2(t_philo *p, int i)
{
	p[i].r_f = 0;
	p[i].l_f = i;
}

void	*philo_delete(t_philo *p)
{
	free(p);
	return (NULL);
}

int	ft_create_t(t_table *table, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < table->count)
	{
		if (pthread_create(&table->t_id[i], 0, philo_do, &philo[i]))
			return (0);
		if (pthread_detach(table->t_id[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}
