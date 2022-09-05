/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phillob.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:55:38 by chfederi          #+#    #+#             */
/*   Updated: 2022/06/13 20:55:40 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILLOB_H
# define PHILLOB_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/time.h>

typedef struct t_args
{
	unsigned long			tt_die;
	int						tt_sleep;
	int						tt_eat;
	int						n;
	int						nc;
	long long				s_time;
	int						pi;
	sem_t					*forks;
	sem_t					*pr;
	sem_t					*check;
	struct t_philo			*ph;
}t_args;

typedef struct timeval	t_timeval;

typedef struct t_philo
{
	int				id;
	pid_t			pid;
	t_args			*args;
	long long		la_eat;
	int				d;
	int				cn;
	t_timeval		last_eat;
	pthread_t		m_id;
}t_philo;

int				ft_isdigit(char *arg);
long long		ft_time(long long l);
void			*ft_calloc(size_t n, size_t size);
long			ctoi(char *s);
void			ft_check_o(t_args *args);
void			start(t_args *args);
void			ft_print(int v, t_philo p, t_args *a);
void			ft_sleep(long long t);
unsigned long	get_time(t_timeval time);
void			destroyer(t_args *a, t_philo *p);
void			philo_run(t_philo *p, t_args *args);
void			process(t_args *args, int i);
void			ft_init(t_args *args, int argc, char **argv);
void			ft_checkarg(char **argv, int argc);
t_philo			*ft_init_p(t_args *args);

#endif