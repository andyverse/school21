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

#include "../minishell.h"

t_env	*last_elem(t_env *list)
{
	if (list == NULL)
		return (NULL);
	if (list->next == NULL)
		return (list);
	else
	{
		while (list->next)
			list = list->next;
		return (list);
	}
}

void	add_list_dash(t_env **e, t_env *new)
{
	t_env	*tmp;

	if (*e == NULL)
		*e = new;
	else
	{
		tmp = last_elem((*e));
		tmp->next = new;
	}
}

void	del_first(t_env **c)
{
	t_env	*tmp;

	tmp = *c;
	*c = tmp->next;
	if (tmp->val)
		free(tmp->val);
	free(tmp);
}

int	tokenizator(t_cmd *cmd, t_data *d)
{
	t_env	*t;
	char	*s;
	int		x;

	t = cmd->c_list;
	while (t)
	{
		x = 1;
		if (check_s(t->val))
		{
			t->val = open_d(ft_strdup(t->val), cmd, d);
//			t->val = open_s(t->val, cmd, d);
//			continue ;
		}
		if (qoutee(t->val))
		{
			if (check_close(t->val) == 1)
				return (1);
			if (qoutee(t->val) == 2)
				x = 2;
			t->val = open_qo(t->val);
		}//дальшее планируется расставлять токены
		t = t->next;
	}
	return (0);
}

int	qparse_cmd(t_cmd *cmd, t_data *d)
{
	int		i;
	int		ch;
	char	*s;

	i = 0;
	ch = 0;
	while (cmd->str[i] == ' ' || cmd->str[i] == '\t')
		i++;
	cmd->c_list = NULL;
	while (ch <= ft_strlen(cmd->str))
	{
		ch = qtoklen(cmd->str, i) - 1;
		s = ft_substr(cmd->str, i, ch + 1);
		add_list_dash(&cmd->c_list, new_list(s, toks(cmd->str[i], 'a')));
		i = i + qtoklen(cmd->str, i);
	}
	tokenizator(cmd, d);
	return (0);
}
//////////////////////////////////////////////////////////////////
void parse_redirect(t_cmd *cmd, struct t_env *c_list)
{
	t_env	*tmp;

	tmp = c_list;
	while (tmp->next)
	{
		if (ft_strncmp(tmp->val, "<", sizeof("<")) == 0)
		{
			tmp->ind = FROM_FILE;
		}
		else if (ft_strncmp(tmp->val, ">", sizeof(">")) == 0)
		{
			tmp->ind = TO_FILE;
		}
		else if (ft_strncmp(tmp->val, ">>", sizeof(">>")) == 0)
			tmp->ind = APPEND;
		else if (ft_strncmp(tmp->val, "<<", sizeof("<<")) == 0)
			tmp->ind = HEREDOC;

		// printf("%d %s\n", tmp->ind, tmp->val);
		tmp = tmp->next;
	}
}

int find_file(t_cmd *cmd)
{
	t_env	*tmp;

	tmp = cmd->c_list;
	while (tmp)
	{
		if (tmp->ind == 11 || tmp->ind == 22 || tmp->ind == 33 || tmp->ind == 44)
		{
			tmp = tmp->next;
			while (tmp && is_all_spaces(tmp->val))
				tmp = tmp->next;
			if (!tmp)
				return (0);
			cmd->file = tmp->val;
			tmp->ind = FF;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
//////////////////////////////////////////////////////////////////
int find_cmd(char **paths, char *s)
{
	int i;
	char *tmp;
	char *c;

	i = -1;
	while (paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		c = ft_strjoin(tmp, s);
		free(tmp);
		if (access(c, 0) == 0)
		{
			// printf("found command %s %s\n", s, c);
			return (1);
		}
	}
	return (0);
}

static int check_redirect(t_env **c_list)
{
	t_env *tmp;

	tmp = *c_list;
	while (tmp && (tmp->ind != 0 || tmp->ind != 11 || tmp->ind != 22
				   || tmp->ind != 33 || tmp->ind != 44))
	{
		if (!tmp->next)
			break ;
		tmp = tmp->next;
		if (tmp->ind == 11 || tmp->ind == 22 || tmp->ind == 33
			|| tmp->ind == 44 || tmp->ind == 0)
			break ;
		// printf("check_redirect %d %s\n", tmp->ind, tmp->val);
	}
	if (!tmp)
		return (0);
	else if (tmp->next)
	{
		if (tmp->ind == 11 || tmp->ind == 22 || tmp->ind == 33
			|| tmp->ind == 44)
		{
			// printf("check_redirect %d %s\n", tmp->ind, tmp->val);
			return (tmp->ind + 1);
		}
		else
			return (0);
	}
}
void set_redirect_index(t_cmd *cmd)
{
	t_env	*tmp;
	// t_env *save;
	char	*str;
	char	*c;

	// save = cmd->c_list;
	tmp = cmd->c_list;
	while (tmp->next)
	{
		if (find_cmd(cmd->cmd_paths, tmp->val))
		{
			tmp->ind = check_redirect(&tmp);
			printf("zzz tmp ind %s %d\n", tmp->val, tmp->ind);
			// save = tmp;
		}
		tmp = tmp->next;
	}
	// cmd->c_list = save;
}
//////////////////////////////////////////////////////////////////
int	pipe_list(t_cmd *cmd)
{
	int	i;
	// t_env *tmp;

	// tmp = cmd->c_list;
	// i = 0;
	// while(tmp->next)
	// {
	// 	if (ft_strncmp(tmp->val, 32, sizeof(SPACE)) == 0);
	// 	{
	// 		printf("%d\n", tmp->val[0]);
	// 	}
	// 	tmp = tmp->next;
	// }

	cmd->pipes = NULL;
	i = 0;
	while (cmd->c_list->next)
	{
		// printf("LISTVAL %s\n", cmd->c_list->val);
		// if (ft_strncmp(cmd->c_list->val, SPACE, sizeof(SPACE)) != 0)
		if (!is_all_spaces(cmd->c_list->val))
		{
			add_list_dash(&cmd->pipes, new_list(cmd->c_list->val, cmd->c_list->ind));
			// printf("%d %s\n", cmd->pipes->ind, cmd->pipes->val);
			i++;
		}
		cmd->c_list = cmd->c_list->next;
	}
	// parse_redirect(cmd->pipes);

	// t_env *temp = cmd->pipes;
	// while (temp)
	// {
	// 	printf("pipe_list cmd->pipes %d %s\n", temp->ind, temp->val);
	// 	temp = temp->next;
	// }
	return (0);
}

static int	list_len(t_env **list, char c)
{
	int	i;

	if (!list)
		return (0);
	i = 0;
	while (*list && (*list)->val[0] != c)
	{
		if ((*list)->ind == 99)
			return (0);
		if ((*list)->ind == 11 || (*list)->ind == 22
			|| (*list)->ind == 33 || (*list)->ind == 44)
		{
			// printf("%d\n", (*list)->ind);
			return (i);
		}

		// printf("%s\n", (*list)->val);
		i++;
		*list = (*list)->next;
	}
	return (i);
}


static char ***alloc_array(int n, t_env *c_list)
{
	char ***arr;
	int  i;
	int  len;
	t_env *tmp;

	tmp = c_list;
	arr = calloc(n + 1, sizeof(char**));
	i = -1;
	while (++i < n && c_list)
	{
		len = list_len(&c_list, PIPE);
		if (len == 0)
			break ;
		// printf("LEN %d\n", len);
		arr[i] = calloc(len + 10, sizeof(char*));
		if (c_list != NULL)
			c_list = c_list->next;
	}
	c_list = tmp;
	return (arr);
}

static void	fulfill_array(int n, char ***arr, t_env *c_list)
{
	int		i;
	int		j;
	// int 	len;
	t_env	*tmp;

	tmp = c_list;
	while (c_list)
	{
		printf("%s\n", c_list->val);
		c_list = c_list->next;
	}
	i = 0;
	c_list = tmp;
	while (i <= n && c_list)
	{
		printf("AAAAAAA = %d LIST %s\n", c_list->ind, c_list->val);
		if (c_list->val[0] == PIPE)
		{
			j = 0;
			c_list = c_list->next;
			i++;
		}
		if (c_list->ind == 11 || c_list->ind == 22
			|| c_list->ind == 33 || c_list->ind == 44)
		{

			if (c_list->next->next && c_list->next->next->val[0] == PIPE)
			{
				i++;
				j = 0;
				c_list = c_list->next->next->next;
			}
			else
				break ;
		}
		// c_list = c_list->next;
		// printf("I = %d LIST %s\n", i, c_list->val);
		// printf("%d %d\n", i, j);
		// if (!arr[i][j])
		// 	printf("qq\n");
		arr[i][j] = c_list->val;
		printf("arrrtrrr J= %d %s\n\n", j, arr[i][j]);
		c_list = c_list->next;
		j++;
	}
	c_list = tmp;
}

int	check_pipe(t_cmd *cmd)
{
	int		x;
	int		i;
	// int		len;
	t_env	*tmp;

	// printf("CHECKING %s\n", cmd->pipes->val);
	tmp = cmd->pipes;
	cmd->n = 0;
	cmd->exec_list = NULL;// это зачем у меня здесь??
	while (tmp)
	{
		if (is_cmd(cmd, tmp)) //у команд индекс = -1
			cmd->n++;
		tmp = tmp->next;
	}
	// printf("Number of commands: %d\n", cmd->n);
	// printf("Number of pipes: %d\n", cmd->is_pipe);
	if (cmd->n <= cmd->is_pipe)
		return (-1);
	return (0);
}



int	is_pipe(t_cmd *cmd)
{
	int		i;
	int		flag;
	char	*s;
	char	x;

	i = -1;
	flag = 0;
	while (cmd->str[++i])
	{
		if (cmd->str[i] == '\"' || cmd->str[i] == '\'')
		{
			x = cmd->str[i];
			i++;
			while (cmd->str[i] != x)
				i++;
		}
		if (cmd->str[i] == PIPE && x % 2 == 0)
			flag++;
	}
	cmd->is_pipe = flag;
	// printf("Num_of_pipes = %d\n", cmd->is_pipe);
	if (flag == 0)
		return (0);
	pipe_list(cmd);
	if (check_pipe(cmd) == -1)
	{
		ft_putstr_fd("minishell: syntax error: unexpected end of file\n", 2);
		return (258);//код подобной ошибки в bash
	}
	// printf("cmdn %d\n", cmd->n);
	cmd->pipe_args = alloc_array(cmd->n, cmd->pipes);
	fulfill_array(cmd->n, cmd->pipe_args, cmd->pipes);

	// cmd->exec_pipe = calloc(cmd->n + 1, sizeof(char*));
	// i = -1;
	// while (++i <= cmd->n && cmd->exec_list->val)
	// {
	// 	// cmd->exec_pipe[i] = calloc(ft_strlen(cmd->exec_list->val), sizeof(char));
	// 	cmd->exec_pipe[i] = cmd->exec_list->val;
	// 	cmd->exec_list = cmd->exec_list->next;
	// }
	// cmd->exec_pipe[i] = NULL;
	cmd->exec_pipe = massiv2(cmd->exec_list);

	// i = -1;
	// while (++i < cmd->n)
	// 	printf("%s\n", cmd->exec_pipe[i]);


	// while (cmd->exec_list)
	// {
	// 	printf("exec_list %d %s\n", cmd->exec_list->ind, cmd->exec_list->val);
	// 	cmd->exec_list = cmd->exec_list->next;
	// }

	// i = 0;
	// while (i < (cmd->n + 2) && cmd->pipe_args[i])
	// {
	// 	flag = 0;
	// 	while (flag < cmd->n + 1 && cmd->pipe_args[i][flag])
	// 	{
	// 		printf("%s\n", cmd->pipe_args[i][flag]);
	// 		flag++;
	// 	}
	// 	i++;
	// }


	// t_env *tmp = cmd->pipes;
	// while (tmp)
	// {
	// 	printf("is_pipe cmd->pipes %d %s\n", tmp->ind, tmp->val);
	// 	tmp = tmp->next;
	// }
	// t_env *temp = cmd->exec_list;
	// while (temp)
	// {
	// 	printf("exec_list %d %s\n", temp->ind, temp->val);
	// 	temp = temp->next;
	// }
	// printf("number of commands %d\n", cmd->n);
	return (1);
}

int is_cmd(t_cmd *cmd, struct t_env *c_list)
{
	char	*tmp;
	char	*c;
	int		i;

	i = 0;
	if (!c_list)
		return (0);
	// printf("Actual VAL %s\n", c_list->val);
	if (cmd->is_pipe == 0)
		cmd->exec_list = NULL;
	while (cmd->cmd_paths[i])
	{
		tmp = ft_strjoin(cmd->cmd_paths[i], "/");
		c = ft_strjoin(tmp, c_list->val);
		free(tmp);
		if (access(c, 0) == 0)
		{
			add_list_dash(&cmd->exec_list, new_list(c, 0));
			// printf("list  >>> %d %s\n", cmd->exec_list->ind, cmd->exec_list->val);

			return (1);
		}
		i++;
	}
	return (0);
}

// int	handling_pipes(int n, t_cmd *cmd)
// {
// 	char	***args;
// 	int		i;

// 	args = malloc(sizeof(char**) * (n + 1));

// 	while (n--)
// 	{
// 		i = 0;
// 		while()
// 	}

// }


// int pipe_args(t_cmd *cmd, t_env *c_list)
// {
// 	int		args;
// 	char	**arr;
// 	t_env	*tmp;
// 	int		i;

// 	tmp = c_list;
// 	args = 1;
// 	printf("1BEFORE %s\n", tmp->val);
// 	tmp = tmp->next;
// 	printf("2BEFORE %s\n", tmp->val);
// 	while (!is_cmd(cmd, tmp) && (ft_strncmp(tmp->val, "|", sizeof("|")) != 0))
// 	{
// 		args++;
// 		if (tmp->next == NULL)
// 			break ;
// 		tmp = tmp->next;
// 	}
// 	printf("AFTER %s\n", tmp->val);
// 	printf("argnum %d\n", args);
// 	arr = malloc(sizeof(char*) * (args + 1));
// 	i = -1;
// 	while (++i <= args)
// 	{
// 		if (ft_strncmp(c_list->val, "|", sizeof("|")) == 0)
// 			c_list = c_list->next;
// 		arr[i] = c_list->val;
// 		printf("A %s\n", arr[i]);
// 		c_list = c_list->next;
// 		i++;
// 	}
// 	return (0);

// }

int check_exitstaus(pid_t pid, t_cmd *cmd)
{
	int	status;

	status = 0;
	if (waitpid(pid, &status, 0) == -1)
		perror("waitpid");
	if (WIFEXITED(status))
		status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		status = WTERMSIG(status);
		if (status == SIGQUIT)
			write(STDOUT_FILENO, "Quit: 3\n", 8);
		if (status == SIGINT)
			write(STDOUT_FILENO, "\n", 1);
		status += 128;
	}
	// printf("exitstatus %d\n", status);
	cmd->exitstatus = status;
	return (status);
}

char	**put_args_together(t_cmd *cmd, struct t_env *c_list)//t_cmd *cmd не используется
{
	int		i;
	int		ind;
	t_env	*tmp;
	char	**c_args;

	i = 0;
	tmp = c_list;
	while(tmp)
	{
		if (ft_strncmp(tmp->val, SPACE, 1) != 0)
			i++;
		tmp = tmp->next;
	}
	// printf("I %d\n", i);
	c_args = malloc(sizeof(char*) * (i + 1));
	if (!c_args)
	{
		perror("malloc");
		return (NULL);
	}
	ind = 0;
	// printf("I%i\n", i);
	while (i >= 0 && c_list)
	{
		// printf("LIST %s\n", c_list->val);
		if (ft_strncmp(c_list->val, SPACE, 1) != 0 && c_list->val[0] != 0)
		{
			c_args[ind] = c_list->val;
			// printf("ARGS %d %s\n", ind, c_args[ind]);
			ind++;
			i--;
		}
		c_list = c_list->next;
	}
	c_args[ind] = NULL;
	return (c_args);
}

int	exec_simple(t_cmd *cmd, struct t_env *c_list, t_data *data)
{
	char	**c_args;
	pid_t	pid;


	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		c_args = put_args_together(cmd, c_list);
		if (!c_args)
			return (check_exitstaus(pid, cmd));
		if (execve(cmd->exec_list->val, c_args, data->env) < 0)
		{
			perror("execve");
			free(c_args);//как правильно зафришить массив, если строки в нем незамаллоченные?
			return (check_exitstaus(pid, cmd));
		}
	}
//	free(c_args);//как правильно зафришить массив, если строки в нем незамаллоченные?
	return (check_exitstaus(pid, cmd));
}