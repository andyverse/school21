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

static char	*find_env(char *s, t_data *d)
{
	t_env	*tmp;

	tmp = d->env1;
	while (tmp)
	{
		if (ft_strncmp(s, tmp->val, ft_strlen(s)) == 0)
			return (tmp->val);
		tmp = tmp->next;
	}
	return (0);
}

static void	changeenv_1(t_data *d)
{
	t_env	*tmp;

	tmp = d->env1;
	while (tmp)
	{
		if (ft_strncmp("OLDPWD", tmp->val, 6) == 0)
		{
			tmp->val = ft_strjoin("OLD", find_env("PWD", d));
			if (!tmp->val)
				exit(3);
			break ;
		}
		tmp = tmp->next;
	}
}

static void	changeenv(t_data *d)
{
	t_env	*tmp;
	char	*s1;

	s1 = getcwd(0, 0);
	tmp = d->env1;
	changeenv_1(d);
	while (tmp)
	{
		if (ft_strncmp("PWD", tmp->val, 3) == 0 && tmp->val)
		{
			tmp->val = ft_strjoin("PWD=", s1);
			if (!tmp->val)
				exit(3);
			break ;
		}
		tmp = tmp->next;
	}
	free(s1);
}

static int	error(int i, t_cmd *cmd)
{
	if (i == 0)
	{
		cmd->exitstatus = 0;
		return (0);
	}
	else
	{
		cmd->exitstatus = 0;
		write(2, "cd: no such file or directory\n", 30);
		return (1);
	}
}

int	ft_cd(char *s, t_cmd *cmd, t_data *d)
{
	int	i;

	if (ft_strlen(s) == 0 || ft_strncmp("~", s, 1) == 0)
	{
		i = chdir(find_env("HOME", d) + 5);
		changeenv(d);
		return (error(i, cmd));
	}
	if (ft_strncmp(s, "..", 2) == 0)
	{
		i = chdir(find_env("OLDPWD", d) + 7);
		changeenv(d);
	}
	else
	{
		i = chdir(s);
		changeenv(d);
	}
	return (error(i, cmd));
}
