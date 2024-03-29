/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phillob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:53:56 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/05 22:56:37 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillob.h"

void	ft_init(t_args *args, int argc, char **argv)
{
	args->n = ctoi(argv[1]);
	args->tt_die = ctoi(argv[2]) * 1000;
	args->tt_eat = ctoi(argv[3]) * 1000;
	args->tt_sleep = ctoi(argv[4]) * 1000;
	args->s_time = ft_time(0);
	if (argc == 6)
		args->nc = ctoi(argv[5]);
	ft_check_o(args);
}

void	ft_checkarg(char **argv, int argc)
{
	int	i;

	i = 1;
	if (argc > 6 || argc < 5)
	{
		write(2, "Error: wrong number of argument\n", 32);
		exit(3);
	}
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 1)
		{
			write(2, "Error: wrong argument\n", 22);
			exit(3);
		}
		i++;
	}
}

t_philo	*ft_init_p(t_args *args)
{
	int		i;
	t_philo	*p;

	p = ft_calloc(sizeof (t_philo), args->n);
	if (!p)
	{
		free(args);
		exit(3);
	}
	i = -1;
	while (++i < args->n)
	{
		p[i].id = i;
		p[i].args = args;
		if (args->nc > 0)
			p[i].d = 0;
		gettimeofday(&p[i].last_eat, NULL);
	}
	return (p);
}

void	init_sem(t_args *args)
{
	sem_unlink("forks");
	sem_unlink("pr");
	sem_unlink("check");
	args->forks = sem_open("forks", O_CREAT, S_IRWXU, args->n);
	if (args->forks == SEM_FAILED)
	{
		write(2, "semaphore error\n", 16);
		exit(3);
	}
	args->pr = sem_open("pr", O_CREAT, S_IRWXU, 1);
	if (args->pr == SEM_FAILED)
	{
		write(2, "semaphore error\n", 16);
		exit(3);
	}
	args->check = sem_open("check", O_CREAT, S_IRWXU, 1);
	if (args->check == SEM_FAILED)
	{
		write(2, "semaphore error\n", 16);
		exit(3);
	}
}

int	main(int argc, char **argv)
{
	t_args	*args;
	int		a;
	int		i;

	ft_checkarg(argv, argc);
	args = malloc(sizeof (t_args));
	if (!args)
		return (0);
	ft_init(args, argc, argv);
	args->ph = ft_init_p(args);
	init_sem(args);
	args->s_time = ft_time(0);
	start(args);
	i = -1;
	waitpid(0, &a, 0);
	while (++i < args->n)
		kill(args->ph[i].pid, SIGTERM);
	destroyer(args, args->ph);
}
