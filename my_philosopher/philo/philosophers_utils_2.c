/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:30:47 by fnochiza          #+#    #+#             */
/*   Updated: 2022/07/06 20:20:58 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	read_argv(int argc, char **argv, t_table *table, int i)
{
	table->min_eat = -1;
	table->count = ft_atoi(argv[1]);
	table->tt_die = ft_atoi(argv[2]) * 1000;
	table->tt_eat = ft_atoi(argv[3]) * 1000;
	table->tt_sleep = ft_atoi(argv[4]) * 1000;
	table->s_time = ft_time(0);
	table->end = 0;
	table->forks = ft_calloc(sizeof(pthread_mutex_t), table->count);
	table->t_id = malloc(sizeof(pthread_t) * table->count);
	if (!table->forks || !table->t_id)
		table->count = 0;
	if (argc == 6)
		table->min_eat = ft_atoi(argv[5]);
	while (i < argc)
	{
		if (ft_checkarg(argv) == 1 || ft_atoi(argv[i]) <= 0)
			return (0);
		i++;
	}
	i = -1;
	while (++i < table->count)
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			return (0);
	return (1);
}

int	table_mute_init(t_table *table)
{
	if (pthread_mutex_init(&table->die, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&table->eating, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&table->print, NULL) != 0)
		return (0);
	return (1);
}

int	clear_structs(t_table *table, t_philo *philo)
{
	if (!table)
		return (0);
	if (table->forks)
		free(table->forks);
	if (table->t_id)
		free(table->t_id);
	free(table);
	if (!philo)
		return (0);
	if (philo->forks)
		free(philo->forks);
	if (philo->table)
		free(philo->table);
	return (0);
}

t_philo	*create_philo(t_table *table)
{
	int		i;
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo), table->count);
	if (!philo)
		return (NULL);
	i = -1;
	while (++i < table->count)
	{
		philo[i].id = i;
		philo[i].last_eat = table->s_time;
		philo[i].table = table;
		philo[i].num_of_eat = 0;
		philo[i].first = i;
		philo[i].second = i + 1;
		philo[i].eat_flag = 0;
		philo[i].forks = table->forks;
		if (table->count == 1)
			philo[i].second = 0;
		if (table->count - 1 == i)
			forks_2(philo, i);
		if (pthread_mutex_init(&philo[i].inc_eat, NULL) != 0)
			return (NULL);
	}
	return (philo);
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
