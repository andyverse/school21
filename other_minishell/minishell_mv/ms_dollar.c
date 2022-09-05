#include "minishell.h"

char	*ft_dollar(char *str, int *i, t_env *envp, t_prm *prm)
{
	t_env	*env;
	int		j;
	char	*tmp;

	j = *i;
	(*i)++;
	while (str[*i] != '\0' && str[*i] != ' ' && str[*i] != '|'
		   && str[*i] != '$' && str[*i] != '<' && str[*i] != '>'
		   && str[*i] != '\'' && str[*i] != '\"')
		(*i)++;
	tmp = ft_substr_mshell(str, j + 1, *i - j - 1, prm);
	env = envp;
	while (env != NULL)
	{
		if (ft_strcmp(tmp, env->name) == 0)
		{
			free(tmp);
			tmp = ft_strdup_mshell(env->val, prm);
			return (tmp);
		}
		env = env->next;
	}
	return (ft_strdup_mshell("", prm));
}

static	char	*ft_question(char *str, int *i, t_prm *prm)
{
	int		j;
	char	*dollar;
	char	*tmp;
	char	*tmp2;

	j = *i + 1;
	tmp2 = ft_substr_mshell(str, 0, *i, prm);
	dollar = ft_itoa_minishell(prm->er_num, prm);
	j++;
	tmp = ft_strjoin_mshell(tmp2, dollar, prm);
	*i = (int)ft_strlen(tmp);
	free(tmp2);
	tmp2 = ft_substr_mshell(str, j, ft_strlen(str) - j, prm);
	free(str);
	str = ft_strjoin_mshell(tmp, tmp2, prm);
	ft_free(&tmp, &tmp2, &dollar);
	return (str);
}

static	char	*ft_no_question(char *str, int *i, t_env *env, t_prm *prm)
{
	int		j;
	char	*dollar;
	char	*tmp;
	char	*tmp2;

	j = *i + 1;
	tmp2 = ft_substr_mshell(str, 0, *i, prm);
	while (str[j] && str[j] != ' ' && str[j] != '<' && str[j] != '>'
		   && str[j] != '|' && str[j] != '\''
		   && str[j] != '\"' && str[j] != '$')
		j++;
	dollar = ft_dollar(str, i, env, prm);
	tmp = ft_strjoin_mshell(tmp2, dollar, prm);
	*i = (int)ft_strlen(tmp);
	free(tmp2);
	tmp2 = ft_substr_mshell(str, j, ft_strlen(str) - j, prm);
	free(str);
	str = ft_strjoin_mshell(tmp, tmp2, prm);
	ft_free(&tmp, &tmp2, &dollar);
	return (str);
}

char	*ft_dollar_check(char *tmp, int *i, t_env *env, t_prm *prm)
{
	int		j;
	char	*str;

	str = ft_strdup_mshell(tmp, prm);
	free(tmp);
	j = *i + 1;
	if (str[j] == '?')
		str = ft_question(str, i, prm);
	else if (str[j] && str[j] != ' ' && str[j] != '<'
		&& str[j] != '>' && str[j] != '$'
		&& str[j] != '|' && str[j] != '\'' && str[j] != '\"')
		str = ft_no_question(str, i, env, prm);
	else
		(*i)++;
	return (str);
}
