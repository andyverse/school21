#include "minishell.h"

static void	ft_heredoc_unlink(t_redir *redir)
{
	while (redir != NULL)
	{
		if (redir->frst != 0 && redir->scnd != 0)
			unlink(redir->name);
		redir = redir->next;
	}
}

static void	ft_free_env_fd(t_prm *prm)
{
	int		i;
	t_env	*envptr;

	i = 0;
	while (prm->fd != NULL && prm->fd[i] != NULL)
		free(prm->fd[i++]);
	free(prm->fd);
	i = 0;
	while (prm->env != NULL && prm->env[i] != NULL)
		free(prm->env[i++]);
	free(prm->env);
	while (prm->envptr != NULL)
	{
		envptr = prm->envptr;
		prm->envptr = prm->envptr->next;
		free(envptr->name);
		free(envptr->sep);
		free(envptr->val);
		free(envptr);
	}
}

static void	ft_free_data(t_prm *prm)
{
	int		i;
	t_redir	*redir;
	t_cmd	*cmd;

	ft_heredoc_unlink(prm->redir);
	ft_free_env_fd(prm);
	while (prm->redir != NULL)
	{
		redir = prm->redir;
		prm->redir = prm->redir->next;
		free(redir->name);
		free(redir->stop);
		free(redir);
	}
	while (prm->cmd != NULL)
	{
		cmd = prm->cmd;
		prm->cmd = prm->cmd->next;
		i = -1;
		while (cmd->cmd[++i] != NULL)
			free(cmd->cmd[i]);
		free(cmd->cmd);
		free(cmd);
	}
}

void	ft_err_exit(int er_num, char *str, t_prm *prm)
{
	char	*error_msg;

	if (str != NULL)
	{
		error_msg = strerror(er_num);
		write(2, str, ft_strlen(str));
		write(2, ": ", 2);
		write(2, error_msg, ft_strlen(error_msg));
		write(2, "\n", 1);
	}
	ft_free_data(prm);
	exit(er_num);
}
