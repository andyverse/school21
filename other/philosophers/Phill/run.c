/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 19:17:41 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/05 18:56:23 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *p)
{
	pthread_mutex_lock(&p->forks[p->l_f]);
	printf("%d\n", p->l_f);
	printf("%d\n", p->r_f);
	ft_print(1, *p);
	pthread_mutex_lock(&p->forks[p->r_f]);
	ft_print(1, *p);
	ft_print(2, *p);
	pthread_mutex_lock(&p->args->check);
	p->la_eat = ft_time(0);
	pthread_mutex_unlock(&p->args->check);
	ft_sleep(p->args->tt_eat / 1000);
	pthread_mutex_lock(&p->eating);
	p->ea++;
	pthread_mutex_unlock(&p->eating);
	pthread_mutex_unlock(&p->forks[p->r_f]);
	pthread_mutex_unlock(&p->forks[p->l_f]);
	ft_print(4, *p);
	ft_sleep(p->args->tt_sleep / 1000);
	ft_print(3, *p);
}

void	end(t_philo *p)
{
	pthread_mutex_lock(&p->args->die);
	p->args->end = 4;
	pthread_mutex_unlock(&p->args->die);
}

int	monitoring2(t_philo *p)
{
	int	i;

	i = -1;
	while (++i < p->args->n)
	{
		pthread_mutex_lock(&p->args->check);
		if (p->args->tt_die < (ft_time(0) - p[i].la_eat) * 1000)
		{
			pthread_mutex_unlock(&p->args->check);
			end(p);
			ft_print(5, p[i]);
			pthread_mutex_lock(&p->args->pr);
			return (1);
		}
		pthread_mutex_unlock(&p->args->check);
		pthread_mutex_lock(&p->eating);
		if (p->ea == p->args->nc + 1)
		{
			end(p);
			pthread_mutex_lock(&p->args->pr);
			return (1);
		}
		pthread_mutex_unlock(&p->eating);
	}
	return (0);
}

void	*monitoring(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	ft_sleep(200);
	while (1)
	{
		if (monitoring2(p) == 1)
			return (0);
		ft_sleep(60);
	}
}
