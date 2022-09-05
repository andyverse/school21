/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:45:09 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/30 04:16:34 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	end(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->die);
	philo->table->end = 4;
	pthread_mutex_unlock(&philo->table->die);
}

int	check_status2(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->table->count)
	{
		pthread_mutex_lock(&philo->table->check);
		if (philo->table->tt_die < (ft_time(0) - philo[i].la_eat) * 1000)
		{
			pthread_mutex_unlock(&philo->table->check);
			end(philo);
			show_logs(5, philo[i]);
			pthread_mutex_lock(&philo->table->pr);
			return (1);
		}
		pthread_mutex_unlock(&philo->table->check);
		pthread_mutex_lock(&philo->eating);
		if (philo->ea == philo->table->nc + 1)
		{
			end(philo);
			pthread_mutex_lock(&philo->table->pr);
			return (1);
		}
		pthread_mutex_unlock(&philo->eating);
	}
	return (0);
}

void	*check_status(void *philo)
{
	t_philo	*phil;

	phil = (t_philo *)philo;
	ft_sleep(200);
	while (1)
	{
		if (check_status2(phil) == 1)
			return (0);
		ft_sleep(60);
	}
}

int	main(int argc, char **argv)
{
	t_table			*table;
	t_philo			*philo;

	if (ft_checkargs(argc, argv) != 1)
		return (0);
	table = malloc(sizeof (t_table));
	if (!table || init_mutex(table))
		return (0);
	ft_init(table, argc, argv);
	if (check_zero(table) == 1)
		return (0);
	philo = philo_init(table);
	table->ph = philo;
	if (!philo)
	{
		free(table->forks);
		free(table->t_id);
		free(table);
		return (0);
	}
	if (!ft_create_t(table, philo))
		return (destroy(philo));
	check_status(philo);
	destroy(philo);
	return (0);
}
