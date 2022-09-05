/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:17:41 by fnochiza          #+#    #+#             */
/*   Updated: 2022/07/06 20:21:12 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>

typedef pthread_mutex_t	t_mute;

typedef struct t_table
{
	int				tt_die;
	int				tt_sleep;
	int				tt_eat;
	int				count;
	int				end;
	int				min_eat;
	long long		s_time;
	pthread_t		*t_id;
	t_mute			die;
	t_mute			*forks;
	t_mute			eating;
	t_mute			print;
}	t_table;

typedef struct t_philo
{
	int				id;
	t_table			*table;
	long long		last_eat;
	int				first;
	int				second;
	int				eat_flag;
	int				num_of_eat;
	t_mute			inc_eat;
	t_mute			*forks;
}t_philo;

long		ft_atoi(char *s);
long long	ft_time(long long l);
void		sleeping(long long t);
void		*check_terms(void *ph);
int			ft_isdigit(char *arg);
void		proccess(t_philo *philo);
void		print_argv(t_table *table);
int			ft_checkarg(char **argv);
t_philo		*create_philo(t_table *table);
void		forks_2(t_philo	*philo, int i);
int			table_mute_init(t_table *table);
void		print_log(int variable, t_philo p);
void		*ft_calloc(size_t size, size_t count);
int			destroy(t_table *table, t_philo *philo);
int			create_thread(t_table *table, t_philo *philo);
int			clear_structs(t_table *table, t_philo *philo);
int			read_argv(int argc, char **argv, t_table *table, int i);

#endif