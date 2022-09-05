#include "minishell.h"

static void	ft_path_free(char **path)
{
	int	i;

	i = -1;
	while (path != NULL && path[++i] != NULL)
		free(path[i]);
	free(path);
}

static char	*ft_path_cmd(char *cmd, char *arg_cmd, int num, t_prm *prm)
{
	char	**path;
	char	*tmp;
	int		i;

	path = ft_split(prm->env[num] + 5, ':');
	if (path == NULL)
		ft_err_exit(12, "malloc", prm);
	tmp = NULL;
	i = -1;
	while (tmp == NULL && path[++i] != NULL)
	{
		tmp = ft_strjoin(path[i], cmd);
		if (tmp == NULL)
			ft_err_exit(12, "malloc", prm);
		if (access(tmp, F_OK) == -1)
		{
			free(tmp);
			tmp = NULL;
		}
	}
	if (tmp == NULL)
		tmp = arg_cmd;
	ft_path_free(path);
	free(cmd);
	return (tmp);
}

static char	*ft_path(char *cmd, t_prm *prm)
{
	char	*path;
	char	*slash;
	int		i;

	if (access(cmd, F_OK) == 0)
		return (cmd);
	i = 0;
	while (prm->env[i] && ft_strncmp(prm->env[i], "PATH=", 5))
		i++;
	if (prm->env[i] == 0)
	{
		access(cmd, F_OK);
		ft_err_exit(errno, cmd, prm);
	}
	slash = ft_strjoin("/", cmd);
	if (slash == 0)
		ft_err_exit(errno, "malloc", prm);
	path = ft_path_cmd(slash, cmd, i, prm);
	return (path);
}

static void	ft_open_and_dup(int i, t_cmd *cmd, t_prm *prm)
{
	int	fd[2];

	fd[0] = -2;
	if (cmd->in)
		fd[0] = open(cmd->in->name, O_RDONLY);
	if (fd[0] == -1)
		ft_err_exit(errno, cmd->in->name, prm);
	fd[1] = -2;
	if (cmd->out && cmd->out->scnd)
		fd[1] = open(cmd->out->name, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (cmd->out && !cmd->out->scnd)
		fd[1] = open(cmd->out->name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] == -1)
		ft_err_exit(errno, cmd->out->name, prm);
	ft_do_dup2(i, fd, cmd, prm);
}

void	ft_child(int i, t_prm *prm)
{
	char	*path;
	int		num;
	t_cmd	*cmd;

	signal(SIGINT, ft_child_signal);
	signal(SIGQUIT, ft_child_signal);
	cmd = prm->cmd;
	num = 0;
	while (num++ < i)
		cmd = cmd->next;
	if (cmd->cmd == 0 || cmd->cmd[0] == 0)
	{
		ft_fd_close(prm, NULL, prm->num);
		ft_err_exit(prm->er_num, NULL, prm);
	}
	ft_open_and_dup(i, cmd, prm);
	if (cmd->build != 0)
		ft_err_exit(ft_run_builds(cmd, prm), NULL, prm);
	path = ft_path(cmd->cmd[0], prm);
	if (execve(path, cmd->cmd, prm->env) == -1)
		ft_err_exit(errno, cmd->cmd[0], prm);
}
