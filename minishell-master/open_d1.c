/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_d1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:38:16 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/22 17:27:41 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*open_dd(int (*i), char *s)
{
	t_env	*a;

	a = NULL;
	while (s[(*i)] != '$' && s[(*i)] != '\'' && s[(*i)] != '\"' && s[(*i)])
		(*i)++;
	if ((*i) > 0)
		a = new_list(ft_substr(s, 0, (*i)), 0);
	return (a);
}

void	open_dd1(int (*i), int (*x), char *s)
{
	(*x) = (*i);
	(*i)++;
	while (s[(*i)] != '\'' && s[(*i)])
		++(*i);
}

void	open_dd2(int (*i), int (*x), char *s)
{
	(*x) = (*i);
	(*i)++;
	while (s[(*i)] != '\"' && s[(*i)])
		++(*i);
}

void	open_dd3(int (*i), int (*x), char *s)
{
	(*x) = (*i);
	while (s[(*i)] != '\"' && s[(*i)] != '\'' && s[(*i)])
		(*i)++;
}

void	open_dd4(int (*i), int (*x), char *s, t_env **a)
{
	open_dd1(i, x, s);
	if ((*x) == 0)
		(*a) = new_list(ft_substr(s, (*x), (*i) - (*x) + 1), 1);
	else
		add_list((*a), new_list(ft_substr(s, (*x), (*i) - (*x) + 1), 1));
	(*i) = (*i) + 1;
}
