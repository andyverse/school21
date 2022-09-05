/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:09:03 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/05 21:04:55 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/time.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct t_args
{
	int				tt_die;
	int				tt_sleep;
	int				tt_eat;
	int				n;
	int				nc;
	int				end;
	long long		s_time;
	pthread_t		*t_id;
	pthread_mutex_t	die;
	pthread_mutex_t	*forks;
	pthread_mutex_t	check;
	pthread_mutex_t	pr;
	struct t_philo	*ph;
}t_args;

typedef struct t_philo
{
	int				id;
	t_args			*args;
	long long		la_eat;
	int				l_f;
	int				r_f;
	int				d;
	int				ea;
	pthread_mutex_t	eating;
	pthread_mutex_t	*forks;
}t_philo;

int			ft_isdigit(char *arg);
int			ft_checkarg(char **argv);
int			ft_check_o(t_args *args);
long		ctoi(char *s);
void		ft_init(t_args *args, int argc, char **argv);
long long	ft_time(long long l);
int			ft_check2(int argc, char **argv);
t_philo		*ft_init_p(t_args *args);
void		*ft_calloc(size_t n, size_t size);
void		ft_sleep(long long t);
void		eat(t_philo *p);
long long	stat_time(long long t);
void		*monitoring(void *arg);
void		ft_print(int v, t_philo p);
int			destroyer(t_philo *p);
void		end(t_philo *p);
int			monitoring2(t_philo *p);
void		*philo_run(void *arg);
int			ft_create_t(t_args *args, t_philo *p);
int			calc_time2(int te, int ts, int n);
void		ft_init_p2(t_philo *p, int i);
void		*ft_init_p3(t_philo *p);
int			init_mutex(t_args *args);

#endif