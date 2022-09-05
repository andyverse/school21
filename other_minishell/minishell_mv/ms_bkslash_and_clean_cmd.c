#include "minishell.h"

char	*ft_find_ch_dollar(t_prm *prm, t_env *env, char *tmp)
{
	int		i;

	i = 0;
	while (tmp[i] != 0)
	{
		if (tmp[i] == '$')
			tmp = ft_dollar_check(tmp, &i, env, prm);
		else
			i++;
	}
	return (tmp);
}

char	*ft_cmd_bkslash2(char *str, int *i, t_env *env, t_prm *prm)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	int		j;

	j = (*i)++;
	while (str[*i] && str[*i] != '\"')
		(*i)++;
	if (str[*i] == 0)
		*i = j + 1;
	tmp = ft_substr_mshell(str, 0, j, prm);
	tmp2 = ft_substr_mshell(str, j + 1, *i - j - 1, prm);
	tmp2 = ft_find_ch_dollar(prm, env, tmp2);
	tmp3 = ft_strjoin_mshell(tmp, tmp2, prm);
	free(tmp);
	free(tmp2);
	tmp2 = ft_strdup_mshell(str + *i + 1, prm);
	tmp = ft_strjoin_mshell(tmp3, tmp2, prm);
	*i = (int)ft_strlen(tmp3);
	ft_free(&tmp2, &tmp3, &str);
	return (tmp);
}

char	*ft_cmd_bkslash1(char *str, int *i, t_prm *prm)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	int		j;

	j = (*i)++;
	while (str[*i] && str[*i] != '\'')
		(*i)++;
	if (str[*i] == 0)
		*i = j + 1;
	tmp = ft_substr_mshell(str, 0, j, prm);
	tmp2 = ft_substr_mshell(str, j + 1, *i - j - 1, prm);
	tmp3 = ft_strjoin_mshell(tmp, tmp2, prm);
	free(tmp);
	free(tmp2);
	tmp2 = ft_strdup_mshell(str + *i + 1, prm);
	tmp = ft_strjoin_mshell(tmp3, tmp2, prm);
	*i = (int)ft_strlen(tmp3);
	ft_free(&tmp2, &tmp3, &str);
	return (tmp);
}

static	void	ft_quotes_clean(char **str, t_env *env, t_prm *prm)
{
	int		flag;
	char	*tmp;
	int		i;

	flag = 0;
	i = 0;
	tmp = ft_strdup_mshell(*str, prm);
	while (tmp[i] != 0)
	{
		if (tmp[i] == '\'')
			tmp = ft_cmd_bkslash1(tmp, &i, prm);
		else if (tmp[i] == '\"')
			tmp = ft_cmd_bkslash2(tmp, &i, env, prm);
		else if (tmp[i] == '$')
			tmp = ft_dollar_check(tmp, &i, env, prm);
		else
			i++;
	}
	free(*str);
	*str = tmp;
}

void	ft_cmd_clean(t_prm *prm)
{
	t_cmd	*tmp;
	int		i;

	tmp = prm->cmd;
	while (tmp != NULL)
	{
		i = 0;
		while (tmp->cmd[i] != 0)
		{
			ft_quotes_clean(&tmp->cmd[i], prm->envptr, prm);
			i++;
		}
		tmp = tmp->next;
	}
}
