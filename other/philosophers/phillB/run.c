/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:41:10 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/06 18:35:52 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillob.h"

void	philo_run(t_philo *p, t_args *args)
{
	if ((p->id) % 2 == 0)
		usleep(200);
	while (1)
	{
		if (p->d == args->nc && p->id == args->n - 1)
			exit(0);
		sem_wait(p->args->forks);
		ft_print(1, *p, args);
		sem_wait(p->args->forks);
		ft_print(1, *p, args);
		ft_print(2, *p, args);
		sem_wait(args->check);
		gettimeofday(&p->last_eat, NULL);
		sem_post(args->check);
		ft_sleep(args->tt_eat / 1000);
		sem_post(p->args->forks);
		sem_post(p->args->forks);
		p->d++;
		ft_print(4, *p, args);
		ft_sleep(args->tt_sleep / 1000);
		ft_print(3, *p, args);
	}
}

unsigned long	get_time(t_timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	*watcher(void *arg)
{
	t_args			*a;
	unsigned long	x;

	a = (t_args *)arg;
	while (1)
	{
		sem_wait(a->check);
		x = get_time(a->ph[a->pi].last_eat);
		sem_post(a->check);
		if (a->tt_die < (ft_time(0) - x) * 1000)
		{
			sem_wait(a->pr);
			printf("%lld %i died\n", ft_time(0) - x, a->pi);
			exit(0);
		}
		ft_sleep(60);
	}
}

void	process(t_args *args, int i)
{
	t_philo	*p;

	p = &args->ph[i];
	args->pi = i;
	if (pthread_create(&args->ph[i].m_id, 0, watcher, args))
	{
		free(args->ph);
		free(args);
		exit(3);
	}
	if (pthread_detach(args->ph[i].m_id))
	{
		free(args->ph);
		free(args);
		exit(3);
	}
	philo_run(p, args);
	exit(3);
}

void	start(t_args *args)
{
	int	i;

	i = 0;
	while (i < args->n)
	{
		args->ph[i].pid = fork();
		if (args->ph[i].pid == -1)
			exit(3);
		if (args->ph[i].pid == 0)
			process(args, i);
		i++;
	}
}
