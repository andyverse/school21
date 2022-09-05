/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:17:41 by fnochiza          #+#    #+#             */
/*   Updated: 2022/07/06 20:31:31 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

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

typedef struct timeval	t_timeval;

typedef struct t_table
{
	unsigned long	tt_die;
	int				tt_sleep;
	int				tt_eat;
	int				count;
	int				pi;
	int				min_eat;
	int				end;
	long long		s_time;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*eating;
	pthread_t		*t_id;
	struct t_philo	*ph;
}	t_table;

typedef struct t_philo
{
	int				id;
	t_table			*table;
	pid_t			pid;
	pthread_t		m_id;
	int				first;
	int				second;
	int				eat_flag;
	int				d;
	int				num_of_eat;
	t_timeval		last_eat;
}t_philo;

long long		ft_time(void);
long			ft_atoi(char *s);
void			*is_die(void *table);
void			sleeping(long long t);
unsigned long	get_time(t_timeval time);
int				ft_checkarg(char **argv);
void			print_argv(t_table *table);
void			create_thread(t_table *table);
t_philo			*create_philo(t_table *table);
void			semaphore_init(t_table *table);
void			proccess(t_table *table, int i);
void			*ft_calloc(size_t size, size_t count);
int				destroy(t_table *table, t_philo *philo);
int				clear_structs(t_table *table, t_philo *philo);
void			print_log(int variable, t_philo p, t_table *table);
int				read_argv(int argc, char **argv, t_table *table, int i);

#endif