/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 00:39:28 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/30 04:23:04 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_zero(t_table *table)
{
	if (table->tt_sleep <= 0 || table->tt_die <= 0 || table->count <= 0
		|| table->tt_eat <= 0 || table->tt_eat <= 0)
	{
		if (table->forks)
			free(table->forks);
		if (table->t_id)
			free(table->t_id);
		write(2, "Error: wrong argument\n", 22);
		return (1);
	}
	return (0);
}

int	ft_checkargs(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
	{
		write(2, "Error: count of arg\n", 20);
		return (0);
	}
	if (is_numbers(argv) == 1)
	{
		write(2, "Error: wrong arg\n", 18);
		return (0);
	}
	return (1);
}

int	init_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->check, NULL) != 0)
	{
		free(table);
		return (1);
	}
	if (pthread_mutex_init(&table->die, NULL) != 0)
	{
		free(table);
		return (1);
	}
	if (pthread_mutex_init(&table->pr, NULL) != 0)
	{
		free(table);
		return (1);
	}
	return (0);
}

void	ft_init(t_table *table, int argc, char **argv)
{
	int	i;

	i = -1;
	table->count = ft_atoi(argv[1]);
	table->forks = ft_calloc(sizeof (pthread_mutex_t), table->count);
	table->tt_die = ft_atoi(argv[2]) * 1000;
	table->tt_eat = ft_atoi(argv[3]) * 1000;
	table->tt_sleep = ft_atoi(argv[4]) * 1000;
	table->s_time = ft_time(0);
	table->t_id = malloc(sizeof(pthread_t) * (table->count));
	if (!table->forks || !table->t_id)
		table->count = 0;
	if (argc == 6)
		table->nc = ft_atoi(argv[5]);
	while (++i < table->count)
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
			table->count = 0;
}
