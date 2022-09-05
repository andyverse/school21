/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:45:25 by fnochiza          #+#    #+#             */
/*   Updated: 2022/07/05 19:21:47 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	forks_2(t_philo	*philo, int i)
{
	philo[i].first = 0;
	philo[i].second = i;
}

void	proccess(t_philo *philo)
{
	pthread_mutex_lock(&philo->forks[philo->first]);
	print_log(1, *philo);
	pthread_mutex_lock(&philo->forks[philo->second]);
	print_log(1, *philo);
	print_log(2, *philo);
	pthread_mutex_lock(&philo->table->eating);
	philo->last_eat = ft_time(0);
	pthread_mutex_unlock(&philo->table->eating);
	sleeping(philo->table->tt_eat / 1000);
	pthread_mutex_lock(&philo->inc_eat);
	philo->num_of_eat++;
	pthread_mutex_unlock(&philo->inc_eat);
	pthread_mutex_unlock(&philo->forks[philo->second]);
	pthread_mutex_unlock(&philo->forks[philo->first]);
	print_log(4, *philo);
	sleeping(philo->table->tt_sleep / 1000);
	print_log(3, *philo);
}

void	*func(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	if ((philo->id + 1) % 2 == 0)
		usleep(110);
	while (1)
	{
		pthread_mutex_lock(&philo->table->die);
		if (philo->table->end == 4)
			break ;
		pthread_mutex_unlock(&philo->table->die);
		proccess(philo);
	}
	return (0);
}

int	create_thread(t_table *table, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < table->count)
	{
		if (pthread_create(&table->t_id[i], 0, func, &philo[i]))
			return (0);
		if (pthread_detach(table->t_id[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	destroy(t_table *table, t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < table->count)
	{
		pthread_mutex_destroy(&philo[i].inc_eat);
		pthread_mutex_destroy(&philo->forks[i]);
	}
	if (philo)
		free(philo);
	if (table->forks)
		free(table->forks);
	if (table->t_id)
		free(table->t_id);
	pthread_mutex_destroy(&table->die);
	pthread_mutex_destroy(&table->eating);
	pthread_mutex_destroy(&table->print);
	free(table);
	(void) table;
	(void) philo;
	return (0);
}
