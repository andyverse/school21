#include "minishell.h"

static int	ft_shlvl_is(t_env *tmp, t_prm *prm)
{
	int		val;

	val = 1;
	while (tmp != NULL)
	{
		if (tmp->val[0] == 0 && ft_strcmp(tmp->name, "SHLVL") == 0)
		{
			free(tmp->sep);
			tmp->sep = ft_strdup_mshell("=", prm);
			free(tmp->val);
			tmp->val = ft_strdup_mshell("1", prm);
			return (1);
		}
		else if (ft_strcmp(tmp->name, "SHLVL") == 0 && tmp->val[0] != 0)
		{
			val = val + ft_atoi(tmp->val);
			free(tmp->val);
			tmp->val = ft_itoa_minishell(val, prm);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void	ft_check_shell_lvl(t_prm *prm)
{
	t_env	*tmp;

	tmp = prm->envptr;
	if (ft_shlvl_is(tmp, prm) == 0)
	{
		tmp = malloc(sizeof(t_env));
		if (tmp == NULL)
			ft_err_exit(12, "malloc", prm);
		tmp->name = "SHLVL";
		tmp->sep = ft_strdup_mshell("=", prm);
		tmp->val = ft_strdup_mshell("1", prm);
		ft_env_add_last(&prm->envptr, tmp);
	}
}
