#include "minishell.h"

static	void	ft_create_list(char *str, t_cmd *tmp, t_prm *prm)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		while (str[i] != 0 && str[i] != '|')
		{
			tmp = ft_creat_node(str, &i, prm);
			ft_list_add(&prm->cmd, tmp);
		}
		if (str[i] == 0)
			break ;
		else
			i++;
	}
}

static	void	ft_stopper_change(t_prm *prm)
{
	char	*str;
	t_redir	*tmp;

	tmp = prm->redir;
	while (tmp != NULL)
	{
		if (tmp->frst != 0 && tmp->scnd != 0)
		{
			tmp->stop = tmp->name;
			str = ft_itoa_minishell(tmp->cmd, prm);
			tmp->name = ft_strjoin_mshell("here_doc", str, prm);
			free(str);
		}
		tmp = tmp->next;
	}
}

static	void	ft_redir_clean(t_prm *prm)
{
	t_redir	*tmp;
	t_env	*env;
	int		i;

	i = 0;
	env = prm->envptr;
	tmp = prm->redir;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->name[i] != 0)
		{
			if (tmp->name[i] == '\'')
				tmp->name = ft_cmd_bkslash1(tmp->name, &i, prm);
			else if (tmp->name[i] == '\"')
				tmp->name = ft_cmd_bkslash2(tmp->name, &i, env, prm);
			else if (tmp->name[i] == '$')
				tmp->name = ft_dollar_check(tmp->name, &i, env, prm);
			else
				i++;
		}
		tmp = tmp->next;
	}
	free(tmp);
}

void	ft_parsing(char *str, t_prm *prm)
{
	t_cmd	*tmp;
	int		i;
	int		n;

	tmp = NULL;
	i = 0;
	n = 0;
	ft_create_list(str, tmp, prm);
	while (str[i] != 0)
	{
		if (str[i] == '|')
		{
			n++;
			i++;
		}
		else
			ft_data_add(&i, str, prm, n);
	}
	ft_cmd_clean(prm);
	ft_redir_clean(prm);
	ft_stopper_change(prm);
}

void	ft_struct_init(t_prm *prm)
{
	prm->num = 0;
	prm->cmd = NULL;
	prm->redir = NULL;
	prm->fd = NULL;
	prm->env = NULL;
	prm->envptr = NULL;
	prm->er_num = 0;
}
