/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 21:39:25 by fnochiza          #+#    #+#             */
/*   Updated: 2022/07/05 19:31:59 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	end(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->die);
	philo->table->end = 4;
	pthread_mutex_unlock(&philo->table->die);
}

int	check_min_eat(t_philo *p, int i, int *eat)
{
	int	j;

	j = 0;
	printf("------------------------\n");
	while (j < p->table->min_eat)
	{
		printf("%d PHIL			%d eat\n", j, p[j].num_of_eat);
		j++;
	}
	printf("------------------------\n");
	if (p[i].num_of_eat == p->table->min_eat)
	{
		if (p[i].eat_flag == 0)
		{
			p[i].eat_flag = 1;
			(*eat)++;
			printf("EAT					%d\n", (*eat));
		}
		if (*eat == p->table->count)
		{
			end(p);
			pthread_mutex_lock(&p->table->print);
			return (1);
		}
	}
	return (0);
}

int	monitoring(t_philo *p)
{
	int			i;
	static int	eat = 0;

	i = -1;
	while (++i < p->table->count)
	{
		pthread_mutex_lock(&p->table->eating);
		if (p->table->tt_die < (ft_time(0) - p[i].last_eat) * 1000)
		{
			pthread_mutex_unlock(&p->table->eating);
			end(p);
			print_log(5, p[i]);
			pthread_mutex_lock(&p->table->print);
			return (1);
		}
		pthread_mutex_unlock(&p->table->eating);
		pthread_mutex_lock(&p->inc_eat);
		if (check_min_eat(p, i, &eat) == 1)
			return (1);
		pthread_mutex_unlock(&p->inc_eat);
	}
	return (0);
}

void	*check_terms(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	sleeping(200);
	while (1)
	{
		if (monitoring(philo) == 1)
			return (0);
		sleeping(60);
	}
}
