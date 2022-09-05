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

int	toks(char c, char a)
{
	if ((c != ' ' && c != '$' && c != '|' && c != '\"' && c != '\''
			&& c != '>' && c != '<' && c != '\0') && a == '\'')
		return (101);
	if (c != ' ' && c != '$' && c != '|' && c != '\"' && c != '\''
		&& c != '>' && c != '<' && c != '\0')
		return (102);
	if (c == ' ')
		return (103);
	return (0);
}

int	toklen2(char *s, int i)
{
	int	l;

	l = 0;
	if (s[i] == '|')
		return (1);
	if (s[i] == '>')
	{
		while (s[i++] == '>')
			l++;
		return (l);
	}
	if (s[i] == '<')
	{
		while (s[i++] == '<')
			l++;
		return (l);
	}
	return (0);
}

int	qoutee(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\'' )
		{
			return (1);
		}
		if (s[i] == '\"' )
		{
			return (2);
		}
		i++;
	}
	return (0);
}

int	count1(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '=')
		i++;
	return (i + 1);
}

int	check_s(char *s)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] == '$')
			x++;
		i++;
	}
	return (x);
}
