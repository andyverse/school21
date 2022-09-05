#include "minishell.h"

static void	ft_free_redir_cmd(t_prm *prm)
{
	int		i;
	t_redir	*redir;
	t_cmd	*cmd;

	while (prm->redir != 0)
	{
		redir = prm->redir;
		prm->redir = prm->redir->next;
		if (redir->frst != 0 && redir->scnd != 0)
			unlink(redir->name);
		free(redir->name);
		free(redir->stop);
		free(redir);
	}
	while (prm->cmd != 0)
	{
		cmd = prm->cmd;
		prm->cmd = prm->cmd->next;
		i = -1;
		while (cmd->cmd[++i] != 0)
			free(cmd->cmd[i]);
		free(cmd->cmd);
		free(cmd);
	}
}

void	ft_free_str(t_prm *prm, char *str)
{
	int		i;

	free(str);
	ft_free_redir_cmd(prm);
	i = 0;
	while (prm->fd && prm->fd[i])
		free(prm->fd[i++]);
	free(prm->fd);
	prm->fd = NULL;
	i = 0;
	while (prm->env != 0 && prm->env[i] != 0)
		free(prm->env[i++]);
	free(prm->env);
	prm->env = NULL;
}
