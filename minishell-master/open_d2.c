/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_d2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:38:16 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/22 17:27:41 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*rev_q(char *s)
{
	int		i;
	int		x;
	char	*str;

	i = 0;
	x = 0;
	while (s[i])
		i++;
	str = malloc(sizeof (char ) * (i + 1));
	while (--i >= 0)
	{
		str[x] = s[i];
		x++;
	}
	str[x] = '\0';
	return (str);
}

static char	*qqq(char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] == '\'' || s[i] == '\"')
		i++;
	str = malloc(sizeof (char ) * i + 1);
	if (!str)
		exit(12);
	i = 0;
	while (s[i] == '\'' || s[i] == '\"')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*open_d3(char *v, t_cmd *cmd, t_data *d)
{
	char	*s;
	char	*str;
	char	*tmp;

	if (v[0] != '\"')
		return (open_s(v, cmd, d));
	s = ft_strtrim(v, "\'\"");
	s = open_s(s, cmd, d);
	str = qqq(v);
	tmp = ft_strjoin(str, s);
	free(s);
	s = tmp;
	str = rev_q(str);
	tmp = ft_strjoin(s, str);
	s = tmp;
	if (!check_s(s))
		return (s);
	return (open_s(s, cmd, d));
}

static char	*open_d1(t_cmd *cmd, t_data *d, t_env *a)
{
	char	*s;
	char	*x;

	s = NULL;
	while (a)
	{
		if ((a->ind == 0 && !check_s(a->val)) || a->ind == 1)
			s = ft_strjoin(s, a->val);
		else
			s = ft_strjoin(s, open_d3(a->val, cmd, d));
		a = a->next;
	}
	ft_free_list(a, free);
	x = ft_strdup(s);
	free(s);
	return (x);
}

char	*open_d(char *s, t_cmd *cmd, t_data *d)
{
	t_env	*a;
	int		i;
	int		x;

	i = 0;
	a = open_dd(&i, s);
	while (i < ft_strlen(s))
	{
		if (s[i] == '\'')
			open_dd4(&i, &x, s, &a);
		else if (s[i] == '\"')
			open_dd5(&i, &x, s, &a);
		else if (i < ft_strlen(s))
		{
			open_dd3(&i, &x, s);
			if (x == 0)
				a = new_list(ft_substr(s, x, i - x), 2);
			else
				add_list(a, new_list(ft_substr(s, x, i - x), 0));
		}
	}
	return (open_d1(cmd, d, a));
}
