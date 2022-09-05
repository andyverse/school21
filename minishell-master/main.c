/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:38:16 by chfederi          #+#    #+#             */
/*   Updated: 2022/09/04 22:02:09 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <readline/history.h>

int	qparse_cmd(t_cmd *cmd, t_data *d);

void	tok(t_cmd *cmd);

// char	g_mask[3] = "000";

int	check_builtin(char *s)
{
	if (ft_strncmp(s, "pwd", ft_strlen("pwd")) == 0)
		return (1);
	if (ft_strncmp(s, "exit", ft_strlen("exit")) == 0)
		return (1);
	if (ft_strncmp(s, "env", ft_strlen("env")) == 0)
		return (1);
	if (ft_strncmp(s, "echo", ft_strlen("echo")) == 0)
		return (1);
	if (ft_strncmp(s, "cd", ft_strlen("cd")) == 0)
		return (1);
	if (ft_strncmp(s, "export", ft_strlen("export")) == 0)
		return (1);
	if (ft_strncmp(s, "unset", ft_strlen("unset")) == 0)
		return (1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
//	printf("1 %zu\n", ft_strlen(s1));
//	printf("2 %zu\n", ft_strlen(s2));
//	if (ft_strlen(s1) != ft_strlen(s2))
//		return (1);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

static int	one_simple_b(t_cmd *cmd, t_data *d)
{
	if (ft_strncmp("cd", cmd->c_list->val, ft_strlen("cd")) == 0)
	{
		ft_cd(cmd->c_list->next->next->val, cmd, d);
		return (1);
	}
	if (ft_strncmp(cmd->c_list->val, "exit", ft_strlen("exit")) == 0)
	{
//		printf("%s\n", cmd->c_list->val);
		ft_exit(&cmd->c_list->next->next->val, d, cmd);
		return (1);
	}
	if (ft_strncmp(cmd->c_list->val, "unset", ft_strlen("unset")) == 0)
	{
//		printf("%s\n", cmd->c_list->next->next->val);
		unset_one(cmd->c_list->next->next->val, d);
		return (1);
	}
	if (stacklen(cmd->c_list) == 1 && check_builtin(cmd->c_list->val))
	{
		if (ft_strncmp(cmd->c_list->val, "exit", ft_strlen("exit")) == 0)
		{
			// printf("%s\n", cmd->c_list->val);
			ft_exit(&cmd->c_list->val, d, cmd);
			return (1);
		}
		if (ft_strncmp(cmd->c_list->val, "env", ft_strlen("env")) == 0)
		{
			env(d);
			return (1);
		}
		if (ft_strncmp(cmd->c_list->val, "pwd", ft_strlen("pwd")) == 0)
		{
			pwd(d);
			return (1);
		}
		// я вот сюда предлагаю пихнуть штуку которая ищет не билтины которые в 1 лист помещаются
		//и вызывает их надеюсь идея понятна
	}
	if (!is_pipe(cmd))
	{
//		find_file(cmd);
		if (is_cmd(cmd, cmd->c_list))
		{
			exec_simple(cmd, cmd->c_list, d);
		}
	}
	else
		{
//			find_file(cmd);
			execute_pipes(cmd, d);
			// printf("ISPIPE\n");
			// t_env *temp = cmd->pipes;
			// while (temp)
			// {
			// 	printf("EXEC%d %s\n", temp->ind, temp->val);
			// 	temp = temp->next;
			// }
		}


	return (0);
}

char	**massiv2(t_env *list)
{
	int		i;
	t_env	*a;
	int		len;
	char	**arr;

	i = -1;
	a = list;
	len = stacklen(a);
	arr = malloc(sizeof (char *) * (len + 2));
	if (!arr)
		exit(12);
	while (++i <= len && a->val)
	{
		arr[i] = ft_strdup(a->val);
		a = a->next;
	}
	arr[i] = NULL;
	return (arr);
}

void	ft_parser(char *s, t_data *d, t_cmd *cmd)
{
	static int	i;

	if (!s)
		return ;
	if (s[0] == 0)
		return ;
	if (check_close(s))
	{
		write(2, "minishell: syntax error is unclosed quote\n", 42);
		return ;
	}
	qparse_cmd(cmd, d);
	parse_redirect(cmd, cmd->c_list);
	find_file(cmd);
	set_redirect_index(cmd);
	// t_env *temp = cmd->c_list;
	// while (temp)
	// {
	// 	printf("%d %s\n", temp->ind, temp->val);
	// 	temp = temp->next;
	// }

	if (check_syn(s) || check_sep(cmd->c_list) == 0)
		return ;
//	if (qparse_cmd(cmd) == 4)
//	{
//		printf("minishell: syntax error is unclosed quote\n");
//		return ;
//	}
// 	 t_cmd *tmp = cmd;
// 	 while (tmp->c_list->val)
// 	 {
// 	 	printf("%s\n", tmp->c_list->val);
// //		 printf("%i\n", tmp->c_list->ind);
// 	 	tmp->c_list = tmp->c_list->next;
// 	 }
//	tok(cmd);
	one_simple_b(cmd, d);
	if (i > 0)
	{
		ft_1free(d->env);
	}
	d->env = massiv2(d->env1);
	i++;
	// d->env = massiv2(d->env1);

	// int len = stacklen(d->env1);
	// int i = -1;
	// while (++i < len && d->env1)
	// {
	// 	printf("%s\n", d->env1->val);
	// 	d->env1 = d->env1->next;
	// }

//	ft_cd(NULL, cmd, d);
//	if (ft_strcmp(s, "exit\n") == 0)
//	{
//		d->ex = 2;
//		return ;
//	}
//	if (ft_strcmp(s, "env\n") == 0)
//	{
//		env(d);
//		return ;
//	}
//	if (ft_strcmp(s, "pwd\n") == 0)
//	{
//		pwd(d);
//		return ;
//	}
//	else
//		printf ("command not found: %s\n", s); //второй фдшник, говорили тебе
}

void	sighand(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data		d;
	t_cmd		*cmd;

	trash(argc, argv);
	sh_lvl(envp);
	d.env1 = init_env(&d, envp);
	cmd= init_cmd(envp);
	while (1)
	{
		signals1();
		cmd->str = readline("<3 ");
		signals2();
		add_history(cmd->str);
		if (!cmd->str)
		{
			printf("<3 exit\n");
			break ;
		}
		ft_parser(cmd->str, &d, cmd);
		free(cmd->str);
		if (d.ex == 2)
			ft_exit(NULL, &d, cmd);
	}
	clear_history();
	exit(3);
}
