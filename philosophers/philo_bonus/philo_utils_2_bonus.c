/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 04:35:20 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/30 04:56:05 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_run(t_philo *philo, t_table *table)
{
	if ((philo->id) % 2 == 0)
		usleep(200);
	while (1)
	{
		if (philo->d == table->nc && philo->id == table->count - 1)
			exit(0);
		sem_wait(philo->table->forks);
		ft_print(1, *philo, table);
		sem_wait(philo->table->forks);
		ft_print(1, *philo, table);
		ft_print(2, *philo, table);
		sem_wait(table->check);
		gettimeofday(&philo->last_eat, NULL);
		sem_post(table->check);
		ft_sleep(table->tt_eat / 1000);
		sem_post(philo->table->forks);
		sem_post(philo->table->forks);
		philo->d++;
		ft_print(4, *philo, table);
		ft_sleep(table->tt_sleep / 1000);
		ft_print(3, *philo, table);
	}
}

unsigned long	get_time(t_timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	*watcher(void *tabl)
{
	t_table			*table;
	unsigned long	x;

	table = (t_table *)tabl;
	while (1)
	{
		sem_wait(table->check);
		x = get_time(table->ph[table->pi].last_eat);
		sem_post(table->check);
		if (table->tt_die < (ft_time(0) - x) * 1000)
		{
			sem_wait(table->pr);
			printf("%lld %i died\n", ft_time(0) - x, table->pi);
			exit(0);
		}
		ft_sleep(60);
	}
}

void	process(t_table *table, int i)
{
	t_philo	*philo;

	philo = &table->ph[i];
	table->pi = i;
	if (pthread_create(&table->ph[i].m_id, 0, watcher, table))
	{
		free(table->ph);
		free(table);
		exit(3);
	}
	if (pthread_detach(table->ph[i].m_id))
	{
		free(table->ph);
		free(table);
		exit(3);
	}
	philo_run(philo, table);
	exit(3);
}

void	start(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->count)
	{
		table->ph[i].pid = fork();
		if (table->ph[i].pid == -1)
			exit(3);
		if (table->ph[i].pid == 0)
			process(table, i);
		i++;
	}
}
