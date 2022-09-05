/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:53:54 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/05 22:25:08 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phillob.h"

void	ft_print(int v, t_philo p, t_args *a)
{
	int	x;

	sem_wait(a->pr);
	x = p.id + 1;
	if (v == 1)
		printf("%lld %i has taken a fork\n", ft_time(0) - p.args->s_time, x);
	if (v == 2)
		printf("%lld %i is eating\n", ft_time(0) - p.args->s_time, x);
	if (v == 3)
		printf("%lld %i is thinking\n", ft_time(0) - p.args->s_time, x);
	if (v == 4)
		printf("%lld %i is sleeping\n", ft_time(0) - p.args->s_time, x);
	if (v == 5)
		printf("%lld %i died\n", ft_time(0) - p.args->s_time, x);
	sem_post(a->pr);
}

void	ft_sleep(long long t)
{
	long long	b;

	b = ft_time(0);
	while (ft_time(0) < (b + t))
	{
		usleep(10);
	}
}

void	destroyer(t_args *a, t_philo *p)
{
	sem_unlink("forks");
	sem_unlink("pr");
	sem_unlink("check");
	sem_close(a->forks);
	sem_close(a->pr);
	sem_close(a->check);
	free(p);
	free(a);
	exit(0);
}
