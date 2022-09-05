/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   someutil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:38:16 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/22 17:27:41 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	indexq(char c)
{
	if (c == '\'')
		return (1);
	if (c == '\"')
		return (2);
	return (0);
}

char	*findenv(char *s, t_data *d, t_cmd *cmd)
{
	t_env	*tmp;

	tmp = d->env1;
	while (tmp->val)
	{
		if (ft_strncmp_env(s, tmp->val, ft_strlen(s)) == 0)
		{
			return (tmp->val + count1(tmp->val));
		}
		tmp = tmp->next;
	}
	if (ft_strncmp_env(s, "?", ft_strlen(s)) == 0)
		return (ft_itoa(cmd->exitstatus));
	return ("");
}

char	*open_s1(char *s, t_cmd *cmd, t_data *d, t_env *a)
{
	char	*st;
	t_env	*t;

	t = a;
	st = NULL;
	while (t)
	{
		if (t->val[0] == '\'' || ft_strlen(t->val) == 0)
		{
			if (t->next)
				t = t->next;
			else
				break ;
		}
		if ((t->val[0] != '$' && t->val[0] != '\"') || t->ind == 1)
			st = ft_strjoin(st, t->val);
		else
			st = ft_strjoin(st, findenv(ft_substr(t->val, 1, ft_strlen(t->val)),
						d, cmd));
		t = t->next;
	}
	return (st);
}

int	check_char(char c)
{
	if (c != ' ' && c != '|'
		&& c != '>' && c != '<' && c != '\0')
		return (1);
	if (c == ' ')
		return (4);
	return (0);
}