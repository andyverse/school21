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

static void	ft_exit1(char **a, t_data *d, t_cmd *cmd)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	if (i > 0)
	{
		ft_putstr_fd("exit \nminishell : exit: too many arguments", 2);
		cmd->exitstatus = 1;
		return ;
	}
	while (a[0][i])
	{
		if (a[0][i] < '0' || a[0][i] > '9')
		{
			ft_putstr_fd("minishell: exit: numeric argument required", 2);
//			ft_free_list(d->env1, free);
			ft_1free(d->env);
			ft_free_list(cmd->c_list, free);
			cmd->exitstatus = 255;
			exit(255);
		}
		i++;
	}
	i = ft_atoi(a[0]);
	ft_1free(d->env);
	ft_free_list(cmd->c_list, free);
//	ft_free_list(d->env1, free);
	cmd->exitstatus = i;
	exit(i);
}

void	ft_exit(char **a, t_data *d, t_cmd *cmd)
{
	if (!a)
	{
		cmd->exitstatus = 0;
		ft_1free(d->env);
//		ft_free_list(d->env1, free);
		ft_free_list(cmd->c_list, free);
		exit(0);
	}
	else
		ft_exit1(a, d, cmd);
}

void	ft_free_list(t_env *a, void (*del)(void *))
{
	t_env	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		if (tmp->val)
			del(tmp->val);
		if (tmp)
			(del)(tmp);
	}
	a = NULL;
}

//void	ft_free(t_cmd *cmd, t_data *d)
//{
//	if (cmd->str)
//		free(cmd->str);
////	if (d->env)
////		ft_1free(d->env);
////	if (d->env1)
////		ft_free_list(&d->env1, free);
////	if (cmd->c_list)
////		ft_free_list(&cmd->c_list, free);
////	if (cmd->c_list1)
////		ft_free_list(&cmd->c_list1, free);
//}

void	*ft_1free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}
