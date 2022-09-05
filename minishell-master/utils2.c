/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:47:39 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/19 00:34:12 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_sep(t_env *c)
{
	t_env	*tmp;

	tmp = c;
	while (tmp)
	{
		if ((tmp->val[0] >= 'a' && tmp->val[0] <= 'z') || (tmp->val[0] >= 'A'
				&& tmp->val[0] <= 'Z'))
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	trash(int argc, char **argv)
{
	(void)argc;
	(void)argv;
}

void	signals1(void)
{
	extern int	rl_catch_signals;

	rl_catch_signals = 0;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, sighand);
}

void	signals2(void)
{
	extern int	rl_catch_signals;

	rl_catch_signals = 1;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

int	check_syn(char *s)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] == '|' || s[i] == '<' || s[i] == '>')
	{
		write(2, "minishell: syntax error near unexpected token\n", 46);
		return (1);
	}
	str = ft_strtrim(s, " \t");
	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] == '|' || str[i] == '<' || str[i] == '>')
	{
		write(2, "minishell: syntax error near unexpected token\n", 46);
		free(str);
		return (1);
	}
	free(str);
	return (0);
}
