/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 04:31:44 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/30 04:50:27 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_init(t_table *table, int argc, char **argv)
{
	table->count = ft_atoi(argv[1]);
	table->tt_die = ft_atoi(argv[2]) * 1000;
	table->tt_eat = ft_atoi(argv[3]) * 1000;
	table->tt_sleep = ft_atoi(argv[4]) * 1000;
	table->s_time = ft_time(0);
	if (argc == 6)
		table->nc = ft_atoi(argv[5]);
	check_zero(table);
}

void	ft_checkarg(char **argv, int argc)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		write(2, "Error: count of arg\n", 20);
		exit(3);
	}
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 1)
		{
			write(2, "Error: wrong arg\n", 18);
			exit(3);
		}
		i++;
	}
}

t_philo	*philo_init(t_table *table)
{
	int		i;
	t_philo	*philo;

	philo = ft_calloc(sizeof (t_philo), table->count);
	if (!philo)
	{
		free(table);
		exit(3);
	}
	i = -1;
	while (++i < table->count)
	{
		philo[i].id = i;
		philo[i].table = table;
		if (table->nc > 0)
			philo[i].d = 0;
		gettimeofday(&philo[i].last_eat, NULL);
	}
	return (philo);
}

void	sem_init(t_table *table)
{
	sem_unlink("forks");
	sem_unlink("pr");
	sem_unlink("check");
	table->forks = sem_open("forks", O_CREAT, S_IRWXU, table->count);
	if (table->forks == SEM_FAILED)
	{
		write(2, "semaphore error\n", 16);
		exit(3);
	}
	table->pr = sem_open("pr", O_CREAT, S_IRWXU, 1);
	if (table->pr == SEM_FAILED)
	{
		write(2, "semaphore error\n", 16);
		exit(3);
	}
	table->check = sem_open("check", O_CREAT, S_IRWXU, 1);
	if (table->check == SEM_FAILED)
	{
		write(2, "semaphore error\n", 16);
		exit(3);
	}
}

int	main(int argc, char **argv)
{
	t_table	*table;
	int		a;
	int		i;

	ft_checkarg(argv, argc);
	table = malloc(sizeof (t_table));
	if (!table)
		return (0);
	ft_init(table, argc, argv);
	table->ph = philo_init(table);
	sem_init(table);
	table->s_time = ft_time(0);
	start(table);
	i = -1;
	waitpid(0, &a, 0);
	while (++i < table->count)
		kill(table->ph[i].pid, SIGTERM);
	destroy(table, table->ph);
}
