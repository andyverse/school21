/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 04:32:35 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/30 04:58:37 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

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

typedef struct t_table
{
	unsigned long			tt_die;
	int						tt_sleep;
	int						tt_eat;
	int						count;
	int						nc;
	long long				s_time;
	int						pi;
	sem_t					*forks;
	sem_t					*pr;
	sem_t					*check;
	struct t_philo			*ph;
}	t_table;

typedef struct timeval	t_timeval;

typedef struct t_philo
{
	int				id;
	pid_t			pid;
	t_table			*table;
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
void			check_zero(t_table *table);
void			start(t_table *table);
void			ft_print(int v, t_philo p, t_table *table);
void			ft_sleep(long long t);
unsigned long	get_time(t_timeval time);
void			sem_init(t_table *table);
void			destroy(t_table *table, t_philo *philo);
void			philo_run(t_philo *p, t_table *args);
void			process(t_table *table, int i);
void			ft_init(t_table *args, int argc, char **argv);
void			ft_checkarg(char **argv, int argc);
t_philo			*philo_init(t_table *table);

#endif