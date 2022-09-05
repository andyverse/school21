#include "minishell.h"

static void	ft_waitpid(pid_t *pid, int num, t_prm *prm)
{
	int	status;
	int	i;

	i = -1;
	while (++i < num)
		waitpid(-1, &status, 0);
	if (prm != NULL)
	{
		if (WIFEXITED(status))
			prm->er_num = WEXITSTATUS(status);
		else
			prm->er_num = status + 128;
	}
	free(pid);
}

void	ft_fd_close(t_prm *prm, int *fd, int num)
{
	int	i;

	i = -1;
	while (++i < num)
	{
		if (prm->fd == NULL || prm->fd[i] == NULL)
			continue ;
		close(prm->fd[i][0]);
		close(prm->fd[i][1]);
		free(prm->fd[i]);
	}
	free(prm->fd);
	prm->fd = NULL;
	if (fd == NULL)
		return ;
	if (fd[0] != 0)
		close(fd[0]);
	if (fd[1] != 0)
		close(fd[1]);
}

void	ft_do_dup2(int i, int *fd, t_cmd *cmd, t_prm *prm)
{
	int	res;

	res = 0;
	if (cmd->in != NULL)
		res = dup2(fd[0], STDIN_FILENO);
	else if (prm->fd != NULL && i != 0)
		res = dup2(prm->fd[i - 1][0], STDIN_FILENO);
	if (res == -1)
		ft_err_exit(errno, "dup2", prm);
	if (cmd->out != NULL)
		res = dup2(fd[1], STDOUT_FILENO);
	else if (i < prm->num - 1 && prm->fd != NULL)
		res = dup2(prm->fd[i][1], STDOUT_FILENO);
	if (res == -1)
		ft_err_exit(errno, "dup2", prm);
	ft_fd_close(prm, fd, prm->num - 1);
}

void	ft_signal_set(int i, t_cmd *cmd)
{
	int		flag;
	int		num;

	num = 0;
	while (num++ < i)
		cmd = cmd->next;
	if (cmd->cmd == NULL || cmd->cmd[0] == NULL)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		return ;
	}
	flag = 0;
	if (ft_strlen(cmd->cmd[0]) > 9 && !ft_strcmp(\
				&cmd->cmd[0][ft_strlen(cmd->cmd[0]) - 10], "/minishell"))
		flag = 1;
	if (flag == 0 && ft_strcmp(cmd->cmd[0], "minishell") != 0)
	{
		signal(SIGINT, ft_pipex_signal);
		signal(SIGQUIT, ft_pipex_signal);
		return ;
	}
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_pipex(t_prm *prm)
{
	int		i;
	pid_t	*pid;

	pid = malloc(prm->num * sizeof(pid_t));
	if (pid == NULL)
		ft_err_exit(errno, "malloc", prm);
	i = -1;
	while (++i < prm->num)
	{
		ft_signal_set(i, prm->cmd);
		pid[i] = fork();
		if (pid[i] == 0)
			ft_child(i, prm);
		if (pid[i] == -1)
		{
			prm->er_num = errno;
			ft_fd_close(prm, NULL, prm->num - 1);
			ft_waitpid(pid, i, NULL);
			ft_err_exit(prm->er_num, "fork", prm);
		}
	}
	ft_fd_close(prm, NULL, prm->num - 1);
	ft_waitpid(pid, prm->num, prm);
}
