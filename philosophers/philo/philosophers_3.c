/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 03:50:22 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/30 04:24:34 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep(long long t)
{
	long long	b;

	b = ft_time(0);
	while (ft_time(0) < (b + t))
	{
		usleep(10);
	}
}

int	destroy(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->table->count)
	{
		pthread_mutex_destroy(&philo[i].eating);
		pthread_mutex_destroy(&philo->table->forks[i]);
	}
	free(philo->table->forks);
	free(philo->table->t_id);
	free(philo->table);
	pthread_mutex_destroy(&philo->table->check);
	pthread_mutex_destroy(&philo->table->die);
	pthread_mutex_destroy(&philo->table->pr);
	free(philo);
	return (0);
}

void	show_logs(int v, t_philo ph)
{
	int	x;

	pthread_mutex_lock(&ph.table->pr);
	x = ph.id + 1;
	if (v == 1)
		printf("%lld %i has taken a fork\n", ft_time(0) - ph.table->s_time, x);
	if (v == 2)
		printf("%lld %i is eating\n", ft_time(0) - ph.table->s_time, x);
	if (v == 3)
		printf("%lld %i is thinking\n", ft_time(0) - ph.table->s_time, x);
	if (v == 4)
		printf("%lld %i is sleeping\n", ft_time(0) - ph.table->s_time, x);
	if (v == 5)
		printf("%lld %i died\n", ft_time(0) - ph.table->s_time, x);
	pthread_mutex_unlock(&ph.table->pr);
}

void	actions(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->l_f]);
	show_logs(1, *philo);
	pthread_mutex_lock(&philo->forks[philo->r_f]);
	show_logs(1, *philo);
	show_logs(2, *philo);
	pthread_mutex_lock(&philo->table->check);
	philo->la_eat = ft_time(0);
	pthread_mutex_unlock(&philo->table->check);
	ft_sleep(philo->table->tt_eat / 1000);
	pthread_mutex_lock(&philo->eating);
	philo->ea++;
	pthread_mutex_unlock(&philo->eating);
	pthread_mutex_unlock(&philo->forks[philo->r_f]);
	pthread_mutex_unlock(&philo->forks[philo->l_f]);
	show_logs(4, *philo);
	ft_sleep(philo->table->tt_sleep / 1000);
	show_logs(3, *philo);
}

void	*philo_do(void *phil)
{
	t_philo		*philo;

	philo = (t_philo *)phil;
	if ((philo->id + 1) % 2 == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&philo->table->die);
		if (philo->table->end == 4)
			break ;
		pthread_mutex_unlock(&philo->table->die);
		actions(philo);
	}
	return (0);
}
