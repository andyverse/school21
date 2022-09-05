/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:41:29 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/05 19:03:36 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init(t_args *args, int argc, char **argv)
{
	int				i;

	i = -1;
	args->n = ctoi(argv[1]);
	args->forks = ft_calloc(sizeof (pthread_mutex_t), args->n);
	args->tt_die = ctoi(argv[2]) * 1000;
	args->tt_eat = ctoi(argv[3]) * 1000;
	args->tt_sleep = ctoi(argv[4]) * 1000;
	args->s_time = ft_time(0);
	args->t_id = malloc(sizeof(pthread_t) * (args->n));
	if (!args->forks || !args->t_id)
		args->n = 0;
	if (argc == 6)
		args->nc = ctoi(argv[5]);
	while (++i < args->n)
		if (pthread_mutex_init(&args->forks[i], NULL) != 0)
			args->n = 0;
}

int	ft_check2(int argc, char **argv)
{
	if (argc > 6 || argc < 5)
	{
		write(2, "Error: wrong number of argument\n", 32);
		return (0);
	}
	if (ft_checkarg(argv) == 1)
	{
		write(2, "Error: wrong argument\n", 22);
		return (0);
	}
	return (1);
}

void	*philo_run(void *arg)
{
	t_philo		*p;

	p = (t_philo *)arg;
	if ((p->id + 1) % 2 == 0)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&p->args->die);
		if (p->args->end == 4)
			break ;
		pthread_mutex_unlock(&p->args->die);
		eat(p);
	}
	return (0);
}

int	ft_create_t(t_args *args, t_philo *p)
{
	int	i;

	i = 0;
	while (i < args->n)
	{
		if (pthread_create(&args->t_id[i], 0, philo_run, &p[i]))
			return (0);
		if (pthread_detach(args->t_id[i]) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_args			*args;
	t_philo			*philo;

	if (ft_check2(argc, argv) != 1)
		return (0);
	args = malloc(sizeof (t_args));
	if (!args || init_mutex(args))
		return (0);
	ft_init(args, argc, argv);
	if (ft_check_o(args) == 1)
		return (0);
	philo = ft_init_p(args);
	args->ph = philo;
	if (!philo)
	{
		free(args->forks);
		free(args->t_id);
		free(args);
		return (0);
	}
	if (!ft_create_t(args, philo))
		return (destroyer(philo));
	monitoring(philo);
	destroyer(philo);
	return (0);
}
