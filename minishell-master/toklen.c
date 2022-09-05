/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toklen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:38:16 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/22 17:27:41 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	qqtoklen(int (*i), int (*t), char *s)
{
	(*i)++;
	(*t)++;
	while (s[(*i)] != '\"' && s[(*i)])
	{
		(*i)++;
		(*t)++;
	}
}

static void	qqtoklen1(int (*i), int (*t), char *s)
{
	(*i)++;
	(*t)++;
	while (s[(*i)] != '\'' && s[(*i)])
	{
		(*i)++;
		(*t)++;
	}
}

static int	qqtoklen2(int i, int l, char *s)
{
	while (s[i++] == ' ')
		l++;
	return (l);
}

int	qtoklen(char *s, int i)
{
	int	l;
	int	t;

	l = 0;
	t = 0;
	if (check_char(s[i]) == 1)
	{
		while (check_char(s[i]) == 1 && s[i] != '\0')
		{
			if (s[i] == '\"')
				qqtoklen(&i, &t, s);
			if (s[i] == '\'')
				qqtoklen1(&i, &t, s);
			i++;
			l++;
		}
		return (l + t);
	}
	if (s[i] == '\"')
		qqtoklen(&i, &t, s);
	if (s[i] == '\'')
		qqtoklen1(&i, &t, s);
	if (s[i] == ' ')
		return (qqtoklen2(i, l, s));
	return (toklen2(s, i));
}
