/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:38:16 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/22 17:27:41 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*open_qo1(char *s, char *st)
{
	st = malloc(sizeof (char ) * ft_strlen(s));
	if (!st)
		exit(12);
	return (st);
}

static void	open_qo2(char *s, char *st, int x, int i)
{
	st[x + 1] = s[i];
	st[x] = '\0';
}

static char	*open_qo3(char *s, char *st, int x, int i)
{
	char	*str;

	open_qo2(s, st, x, i);
	str = ft_strdup(st);
	free(st);
	free(s);
	return (str);
}

static char	*open_qo5(char *s, int (*x), int (*i))
{
	int		a;
	int		b;
	char	*st;

	a = 0;
	b = 0;
	st = NULL;
	st = open_qo1(s, st);
	while ((s[a] != '\"' && s[a] != '\'') && s[a])
		st[b++] = s[a++];
	(*x) = b;
	(*i) = a;
	return (st);
}

char	*open_qo(char *s)
{
	int		i;
	char	*st;
	int		x;

	i = 0;
	x = 0;
	st = open_qo5(s, &x, &i);
	while (s[i])
	{
		if (s[i] == '\"' )
		{
			while (s[++i] != '\"' && s[i])
				st[x++] = s[i];
			i++;
		}
		else if (s[i] == '\'' )
		{
			while (s[++i] != '\'' && s[i])
				st[x++] = s[i];
			i++;
		}
		else if (s[i] != '\"' && s[i] != '\'')
			st[x++] = s[i++];
	}
	return (open_qo3(s, st, x, i));
}
