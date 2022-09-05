/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:25:38 by mcherrie          #+#    #+#             */
/*   Updated: 2022/06/17 14:25:44 by mcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int g_exit_status;

static void	ft_close_saved_fd(int save)
{
	// close(0);
	dup2(save, 0);
	close(save);
}

static void	pipe_close(t_cmd *cmd, int fd0, int fd1, int i)
{
	if (cmd->pipe_args[i + 1])
	{
		dup2(fd0, 0);
		close(fd0);
		close(fd1);
	}
}

static void	execve_handler(t_cmd *cmd, t_data *data, int i)
{
	int	exit_status;
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		execve(cmd->exec_pipe[i], cmd->pipe_args[i], data->env);
		ft_putstr_fd("Minisheldon: ", 2);
		// g_exit_status = 127;
		// free_pipe_struct(exec);
		exit(127);
	}
	wait(&exit_status);
	if (WIFSIGNALED(exit_status))
	{
		if (WTERMSIG(exit_status) != 13)
			g_exit_status = 128 + WTERMSIG(exit_status);
		if (WTERMSIG(exit_status) == SIGQUIT)
			write(2, "Quit\n", 5);
	}
	else
		g_exit_status = WEXITSTATUS(exit_status);
}

static void	child_proc(t_cmd *cmd, t_data *data, int *pipefd, int i)
{
	if (cmd->pipe_args[i + 1])
	{
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		close(pipefd[0]);
	}
//	set_redirect(cmd, cmd->pipes, pipefd);
	execve_handler(cmd, data, i);
	exit(g_exit_status);
}

static void	pipex(t_cmd *cmd, t_data *data, int i)
{
	int	pid;
	int	pipefd[2];
	int	exit_status;

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
		child_proc(cmd, data, pipefd, i);
	wait(&exit_status);
	if (WIFSIGNALED(exit_status))
	{
		if (WTERMSIG(exit_status) != 13)
			g_exit_status = 128 + WTERMSIG(exit_status);
		if (WTERMSIG(exit_status) == SIGQUIT)
			write(2, "Quit\n", 5);
	}
	else
		g_exit_status = WEXITSTATUS(exit_status);
	// close (0);
	pipe_close(cmd, pipefd[0], pipefd[1], i);
}

void	execute_pipes(t_cmd *cmd, t_data *data)
{
	int		save;
	int		i;

	save = dup(0);
	i = 0;
	// printf("FILE %s\n", cmd->file);
	// printf("REDIRECT %d\n", cmd->redirect);

	// printf("%s\n", cmd->pipe_args[i][1]);
	while (cmd->pipe_args[i])
	{
		pipex(cmd, data, i);
		i++;
	}
	ft_close_saved_fd(save);
}
