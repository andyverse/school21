#include "minishell.h"

void	ft_builds_set(t_cmd *cmd)
{
	while (cmd != NULL)
	{
		if (cmd->cmd[0] != 0)
		{
			if (ft_strcmp(cmd->cmd[0], "echo") == 0)
				cmd->build = 1;
			else if (ft_strcmp(cmd->cmd[0], "cd") == 0)
				cmd->build = 2;
			else if (ft_strcmp(cmd->cmd[0], "pwd") == 0)
				cmd->build = 3;
			else if (ft_strcmp(cmd->cmd[0], "export") == 0)
				cmd->build = 4;
			else if (ft_strcmp(cmd->cmd[0], "unset") == 0)
				cmd->build = 5;
			else if (ft_strcmp(cmd->cmd[0], "env") == 0)
				cmd->build = 6;
			else if (ft_strcmp(cmd->cmd[0], "exit") == 0)
				cmd->build = 7;
		}
		cmd = cmd->next;
	}
}

int	ft_build_exit(t_cmd *cmd, t_prm *prm)
{
	write(1, "exit\n", 5);
	if (cmd->cmd[1] != NULL)
		ft_err_exit((unsigned char) ft_atoi(cmd->cmd[1]), \
                NULL, prm);
	else
		ft_err_exit(0, NULL, prm);
	return (0);
}

int	ft_run_builds(t_cmd *cmd, t_prm *prm)
{
	if (cmd->build == 1)
		return (ft_build_echo(cmd, prm));
	if (cmd->build == 2)
		return (ft_build_cd(cmd, prm->envptr, prm));
	if (cmd->build == 3)
		return (ft_build_pwd(prm));
	if (cmd->build == 4)
		return (ft_build_export(cmd, prm));
	if (cmd->build == 5)
		return (ft_build_unset(cmd, prm));
	if (cmd->build == 6)
		return (ft_build_env(prm->envptr));
	if (cmd->build == 7)
		return (ft_build_exit(cmd, prm));
	return (0);
}

void	ft_build_redup(int fd, t_prm *prm)
{
	if (fd > -1)
	{
		if (dup2(fd, STDOUT_FILENO) == -1) {
			close(fd);
			ft_err_exit(errno, "dup2", prm);
		}
		close(fd);
	}
}

int	ft_build_dup(t_cmd *cmd, t_prm *prm)
{
	int	fd1;
	int	fd_new;

	if (cmd->out == NULL)
		return (-1);
	if (cmd->out->scnd != 0)
		fd1 = open(cmd->out->name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		fd1 = open(cmd->out->name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd1 == -1)
		ft_err_exit(errno, cmd->out->name, prm);
	fd_new = dup(STDOUT_FILENO);
	if (fd_new == -1)
	{
		close(fd1);
		ft_err_exit(errno, "dup", prm);
	}
	if (dup2(fd1, STDOUT_FILENO) == -1)
	{
		close(fd1);
		close(fd_new);
		ft_err_exit(errno, "dup2", prm);
	}
	close(fd1);
	return (fd_new);
}
