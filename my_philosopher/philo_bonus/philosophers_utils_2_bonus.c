/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils_2_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:30:47 by fnochiza          #+#    #+#             */
/*   Updated: 2022/07/06 20:30:55 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	read_argv(int argc, char **argv, t_table *table, int i)
{
	table->count = ft_atoi(argv[1]);
	table->tt_die = ft_atoi(argv[2]) * 1000;
	table->tt_eat = ft_atoi(argv[3]) * 1000;
	table->tt_sleep = ft_atoi(argv[4]) * 1000;
	table->s_time = ft_time();
	if (argc == 6)
		table->min_eat = ft_atoi(argv[5]);
	if (ft_checkarg(argv) == 1)
		return (0);
	while (i < argc)
	{
		if (ft_atoi(argv[i]) <= 0)
			return (0);
		i++;
	}
	return (1);
}

void	semaphore_init(t_table *table)
{
	sem_unlink("forks");
	sem_unlink("print");
	sem_unlink("eating");
	table->forks = sem_open("forks", O_CREAT, S_IRWXU, table->count);
	if (table->forks == SEM_FAILED)
	{
		write(2, "sem error\n", 11);
		exit(3);
	}
	table->eating = sem_open("eating", O_CREAT, S_IRWXU, 1);
	if (table->eating == SEM_FAILED)
	{
		write(2, "sem error\n", 11);
		exit(3);
	}
	table->print = sem_open("print", O_CREAT, S_IRWXU, 1);
	if (table->print == SEM_FAILED)
	{
		write(2, "sem error\n", 11);
		exit(3);
	}
}

unsigned long	get_time(t_timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

t_philo	*create_philo(t_table *table)
{
	int		i;
	t_philo	*philo;

	philo = ft_calloc(sizeof(t_philo), table->count);
	if (!philo)
		exit(3);
	i = -1;
	while (++i < table->count)
	{
		philo[i].id = i;
		philo[i].table = table;
		philo[i].eat_flag = 0;
		if (table->min_eat > 0)
			philo[i].num_of_eat = 0;
		gettimeofday(&philo[i].last_eat, NULL);
	}
	return (philo);
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
			exit(0);
		}
	}
	return (0);
}
