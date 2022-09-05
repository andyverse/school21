/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:15:29 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/05 17:15:00 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_init_p(t_args *args)
{
	t_philo		*p;
	int			i;

	i = -1;
	p = ft_calloc(sizeof (t_philo), args->n);
	if (!p)
		return (NULL);
	while (++i < args->n)
	{
		p[i].id = i;
		p[i].la_eat = args->s_time;
		p[i].args = args;
		p[i].l_f = i;
		p[i].r_f = i + 1;
		p[i].ea = 0;
		p[i].forks = args->forks;
		if (args->n == 1)
			p[i].r_f = 0;
		if (i == args->n - 1)
			ft_init_p2(p, i);
		if (pthread_mutex_init(&p[i].eating, NULL) != 0)
			return (ft_init_p3(p));
	}
	return (p);
}

void	ft_init_p2(t_philo *p, int i)
{
	p[i].r_f = 0;
	p[i].l_f = i;
}

void	*ft_init_p3(t_philo *p)
{
	free(p);
	return (NULL);
}

int	init_mutex(t_args *args)
{
	if (pthread_mutex_init(&args->check, NULL) != 0)
	{
		free(args);
		return (1);
	}
	if (pthread_mutex_init(&args->die, NULL) != 0)
	{
		free(args);
		return (1);
	}
	if (pthread_mutex_init(&args->pr, NULL) != 0)
	{
		free(args);
		return (1);
	}
	return (0);
}
