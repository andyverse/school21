#include "minishell.h"

t_env	*ft_env_find_tail(t_env *tail)
{
	while (tail->next != NULL)
		tail = tail->next;
	return (tail);
}

void	ft_env_add_last(t_env **env, t_env *new)
{
	t_env	*tmp;

	if (*env != NULL)
	{
		tmp = ft_env_find_tail(*env);
		tmp->next = new;
	}
	else
		*env = new;
}

t_env	*ft_env_new(char *env, t_prm *prm)
{
	t_env	*new;
	int		i;

	i = 0;
	new = malloc(sizeof(t_env));
	if (new == NULL)
		ft_err_exit(12, "malloc", prm);
	while (env[i] != 0 && env[i] != '=')
		i++;
	new->name = ft_substr_mshell(env, 0, i, prm);
	new->sep = ft_substr_mshell(env, i, 1, prm);
	if (env[i])
		new->val = ft_substr_mshell(env, i + 1, ft_strlen(env) - i + 1, prm);
	else
		new->val = ft_strdup_mshell("\0", prm);
	new->next = NULL;
	return (new);
}

void	ft_parse_env(char **env, t_env **envp, t_prm *prm)
{
	int		i;
	t_env	*tmp;

	i = 0;
	while (env[i] != NULL)
	{
		tmp = ft_env_new(env[i], prm);
		ft_env_add_last(envp, tmp);
		i++;
	}
}
