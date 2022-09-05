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

static int	open_ss1(char *s)
{
	int		i;

	i = 0;
	if (s[i] == '\'' || s[i] == '\"')
		i++;
	while (s[i] != '$' && s[i] != '\"' && s[i] != '\'')
		i++;
	if (s[i] == '\'' || s[i] == '\"')
		i++;
	return (i);
}

static int	open_ss2(char *s, int i)
{
	while (s[i] == '\"' || s[i] == '\'')
		i++;
	return (i);
}

static int	open_ss3(char *s, int i)
{
	i++;
	while (s[i] != '$' && s[i] != ' ' && s[i] && s[i] != '\"'
		&& s[i] != '\'')
		i++;
	return (i);
}

static void	open_ss4(char *s, t_env *a, int (*i), int (*x))
{
	(*i) = open_ss2(s, (*i));
	(*x) = open_ss2(s, (*i));
	if (s[(*i)] != '\0')
	{
		while (s[(*i)])
			(*i)++;
		add_list(a, new_list(ft_substr(s, (*x), (*i) - (*x)), 0));
	}
	add_list(a, new_list("", 1));
}

char	*open_s(char *s, t_cmd *cmd, t_data *d)
{
	int		i;
	int		x;
	char	*str;
	t_env	*a;

	i = open_ss1(s);
	str = ft_substr(s, 0, i);
	a = new_list(str, 122);
	if (s[i] != '\0')
	{
		while (check_s(s + i) && s[i])
		{
			if (s[i] == '$' || s[i] == ' ' || s[i] == '\"' || s[i] == '\'' )
			{
				x = i;
				i = open_ss3(s, i);
				str = ft_substr(s, x, i - x);
				add_list(a, new_list(str, indexq(s[i])));
			}
			else
				i++;
		}
		open_ss4(s, a, &i, &x);
	}
	return (open_s1(s, cmd, d, a));
}