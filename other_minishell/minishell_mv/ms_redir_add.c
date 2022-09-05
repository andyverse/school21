#include "minishell.h"

static	void	ft_cmd_add(char *str, int *i)
{
	while (str[*i] && str[*i] != ' ' && str[*i] != '<'
		   && str[*i] != '>' && str[*i] != '|')
	{
		if (str[*i] == '\'')
			ft_bkslash1(str, i);
		else if (str[*i] == '\"')
			ft_bkslash2(str, i);
		else
			(*i)++;
	}
}

static	void	ft_init_redir(t_redir *redir, int n, t_prm *prm)
{
	if (redir == NULL)
		ft_err_exit(12, "malloc", prm);
	redir->frst = 0;
	redir->stop = NULL;
	redir->scnd = 0;
	redir->cmd = n;
	redir->next = NULL;
}

static	void	ft_check_redir(char *str, int *i, t_redir *redir)
{
	if (str[(*i)++] == '<')
		redir->frst = 1;
	if (str[*i] == '<' || str[*i] == '>')
	{
		redir->scnd = 1;
		(*i)++;
	}
}

static	void	ft_cmd_redir(char *str, int *i, t_prm *prm, int n)
{
	t_redir	*redir;
	int		k;

	redir = malloc(sizeof(t_redir));
	ft_init_redir(redir, n, prm);
	ft_check_redir(str, i, redir);
	while (str[*i] == ' ')
		(*i)++;
	while (str[*i] && str[*i] != '|' && str[*i] != ' '
		   && str[*i] != '<' && str[*i] != '>')
	{
		k = *i;
		while (str[*i] && str[*i] != ' '
			   && str[*i] != '<' && str[*i] != '>' && str[*i] != '|')
		{
			if (str[*i] == '\'')
				ft_bkslash1(str, i);
			else if (str[*i] == '\"')
				ft_bkslash2(str, i);
			else
				(*i)++;
		}
		redir->name = ft_substr_mshell(str, k, *i - k, prm);
	}
	ft_redir_add_back(&prm->redir, redir);
}

void	ft_data_add(int *i, char *str, t_prm *prm, int n)
{
	int		j;
	t_cmd	*cmd;
	int		num;

	cmd = prm->cmd;
	j = 0;
	while (j++ < n)
		cmd = cmd->next;
	num = 0;
	while (str[*i] && str[*i] != '|')
	{
		if (str[*i] == ' ')
			(*i)++;
		else if (str[*i] == '<' || str[*i] == '>')
			ft_cmd_redir(str, i, prm, n);
		else
		{
			j = *i;
			ft_cmd_add(str, i);
			cmd->cmd[num] = ft_substr_mshell(str, j, *i - j, prm);
			num++;
			cmd->cmd[num] = NULL;
		}
	}
}
