/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils_3_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:45:25 by fnochiza          #+#    #+#             */
/*   Updated: 2022/07/06 20:30:51 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	repast(t_philo	*philo, t_table *table, int i)
{
	if ((philo->id + 1) % 2 == 0)
		usleep(200);
	while (1)
	{
		if (table->ph[i].num_of_eat == table->min_eat && \
			table->ph[i].id + 1 == table->count)
			exit(0);
		sem_wait(table->forks);
		print_log(1, *philo, table);
		sem_wait(table->forks);
		print_log(1, *philo, table);
		print_log(2, *philo, table);
		sem_wait(table->eating);
		gettimeofday(&philo->last_eat, NULL);
		sem_post(table->eating);
		sleeping(table->tt_eat / 1000);
		sem_post(table->forks);
		sem_post(table->forks);
		table->ph[i].num_of_eat++;
		print_log(4, *philo, table);
		sleeping(table->tt_sleep / 1000);
		print_log(3, *philo, table);
	}
}

void	*is_die(void *tab)
{
	t_table			*table;
	unsigned long	eating_time;

	table = (t_table *) tab;
	while (1)
	{
		sem_wait(table->eating);
		eating_time = get_time(table->ph[table->pi].last_eat);
		sem_post(table->eating);
		if (table->tt_die < (ft_time() - eating_time) * 1000)
		{
			sem_wait(table->print);
			printf("%lld %i died\n", ft_time() - eating_time, table->pi + 1);
			exit(0);
		}
		sleeping(10);
	}
}

void	proccess(t_table *table, int i)
{
	t_philo	*philo;

	philo = &table->ph[i];
	table->pi = i;
	if (pthread_create(&table->ph[i].m_id, 0, is_die, table))
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
	repast(philo, table, table->pi);
	exit(3);
}

void	create_thread(t_table *table)
{
	int	i;
	int	pid;

	i = 0;
	pid = 1;
	while (i < table->count && pid > 0)
	{
		pid = fork();
		table->ph[i].pid = pid;
		if (table->ph[i].pid == -1)
			exit(3);
		if (table->ph[i].pid == 0)
			proccess(table, i);
		i++;
	}
}

int	destroy(t_table *table, t_philo *philo)
{
	sem_unlink("forks");
	sem_unlink("eating");
	sem_unlink("print");
	sem_close(table->forks);
	sem_close(table->eating);
	sem_close(table->print);
	free(philo);
	free(table);
	exit(0);
	return (0);
}
