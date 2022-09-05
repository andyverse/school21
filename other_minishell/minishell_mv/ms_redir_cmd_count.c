#include "minishell.h"

void	ft_redir_to_cmd(t_redir *redir, t_cmd *cmd)
{
	int	number;
	int	i;

	i = 0;
	while (cmd != NULL && redir)
	{
		number = redir->cmd;
		while (i < number)
		{
			cmd = cmd->next;
			i++;
		}
		if (redir->frst)
			cmd->in = redir;
		else
			cmd->out = redir;
		redir = redir->next;
	}
}

int	ft_cmd_counter(t_cmd *cmd)
{
	int	count;

	count = 0;
	while (cmd != NULL)
	{
		count = count + 1;
		cmd = cmd->next;
	}
	return (count);
}
