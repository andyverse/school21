/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:45:07 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/30 04:19:57 by fnochiza         ###   ########.fr       */
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
	int				nc;
	int				end;
	long long		s_time;
	pthread_t		*t_id;
	pthread_mutex_t	die;
	pthread_mutex_t	*forks;
	pthread_mutex_t	check;
	pthread_mutex_t	pr;
	struct t_philo	*ph;
}	t_table;

typedef struct t_philo
{
	int				id;
	t_table			*table;
	long long		la_eat;
	int				l_f;
	int				r_f;
	int				d;
	int				ea;
	pthread_mutex_t	eating;
	pthread_mutex_t	*forks;
}t_philo;

int			is_digit(char *arg);
void		end(t_philo *philo);
long long	ft_time(long long l);
void		ft_sleep(long long t);
void		*philo_do(void *table);
void		actions(t_philo *philo);
int			is_numbers(char **argv);
int			destroy(t_philo *philo);
int			ft_atoi(const char *str);
void		*philo_delete(t_philo *p);
int			init_mutex(t_table *table);
int			check_zero(t_table *table);
void		*check_status(void *philo);
t_philo		*philo_init(t_table *table);
void		show_logs(int v, t_philo ph);
int			check_status2(t_philo *philo);
void		philo_init_2(t_philo *p, int i);
void		*ft_calloc(size_t n, size_t size);
int			ft_checkargs(int argc, char **argv);
int			ft_create_t(t_table *table, t_philo *philo);
void		ft_init(t_table *table, int argc, char **argv);

#endif