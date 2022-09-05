#include "minishell.h"

static	void	ft_size_word(char *str, int *i)
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

static int	ft_count_wrds(char *str, int *i)
{
	int		num;

	num = 0;
	while (str[*i] != 0 && str[*i] != '|')
	{
		if (str[*i] == ' ')
			(*i)++;
		else if (str[*i] == '<' || str[*i] == '>')
			ft_redirect(str, i);
		else
		{
			num++;
			ft_size_word(str, i);
		}
	}
	return (num);
}

static	t_cmd	*ft_args_find_tail(t_cmd *list)
{
	t_cmd	*tail;

	tail = NULL;
	while (list != NULL)
	{
		tail = list;
		list = list->next;
	}
	return (tail);
}

void	ft_list_add(t_cmd **cmd, t_cmd *new)
{
	if (*cmd != NULL)
		ft_args_find_tail(*cmd)->next = new;
	else
		*cmd = new;
}

t_cmd	*ft_creat_node(char *str, int *i, t_prm *prm)
{
	int		count_wrd;
	t_cmd	*node;

	node = malloc(sizeof(t_cmd));
	if (node == NULL)
		ft_err_exit(12, "malloc", prm);
	node->build = 0;
	node->in = NULL;
	node->out = NULL;
	node->next = NULL;
	count_wrd = ft_count_wrds(str, i);
	node->cmd = malloc(sizeof(char *) * (count_wrd + 1));
	if (node->cmd == NULL)
		ft_err_exit(12, "malloc", prm);
	node->cmd[0] = NULL;
	return (node);
}
