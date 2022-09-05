#include "minishell.h"

static	int	ft_env_size(t_env *env_p)
{
	int		i;
	t_env	*tmp;

	tmp = env_p;
	i = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static	void	ft_array_creat(t_env *env_p, char ***env, int len, t_prm *prm)
{
	char	*array;
	int		i;

	i = -1;
	while (++i < len)
	{
		(*env)[i] = ft_strdup_mshell(env_p->name, prm);
		if (*env_p->sep)
		{
			array = ft_strjoin_mshell((*env)[i], env_p->sep, prm);
			free((*env)[i]);
			(*env)[i] = array;
		}
		if (*env_p->val)
		{
			array = ft_strjoin_mshell((*env)[i], env_p->val, prm);
			free((*env)[i]);
			(*env)[i] = array;
		}
		env_p = env_p->next;
	}
	(*env)[i] = NULL;
}

void	ft_env_list_arr(t_env *env_p, char ***env, t_prm *prm)
{
	int		env_len;

	env_len = ft_env_size(env_p);
	*env = malloc(sizeof(char *) * (env_len + 1));
	if (*env == NULL)
		ft_err_exit(12, "malloc", prm);
	ft_array_creat(env_p, env, env_len, prm);
}
