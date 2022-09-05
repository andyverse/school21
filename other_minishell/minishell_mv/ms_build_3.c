#include "minishell.h"

static t_env	*ft_one_lst(t_env *env, t_prm *prm)
{
	t_env	*one;

	one = malloc(sizeof(t_env));
	if (one == NULL)
		ft_err_exit(12, "malloc", prm);
	one->name = ft_strdup_mshell(env->name, prm);
	one->sep = ft_strdup_mshell(env->sep, prm);
	one->val = ft_strdup_mshell(env->val, prm);
	one->next = NULL;
	return (one);
}

static int	if_not_cmd1(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->sep[0])
			printf("declare -x %s%s\"%s\"\n", (tmp)->name, \
					(tmp)->sep, (tmp)->val);
		else
			printf("declare -x %s%s%s\n", (tmp)->name, \
					(tmp)->sep, (tmp)->val);
		tmp = (tmp)->next;
	}
	return (0);
}

void	ft_search_dups(t_env *env, t_env *new, t_prm *prm)
{
	t_env	*tmp2;

	while (new != 0)
	{
		tmp2 = env;
		while (tmp2 != 0)
		{
			if (ft_strcmp(new->name, tmp2->name) == 0)
			{
				if (new->sep[0] != 0 && tmp2->sep[0] == 0)
				{
					free(tmp2->sep);
					tmp2->sep = ft_strdup_mshell(new->sep, prm);
				}
				free(tmp2->val);
				tmp2->val = ft_strdup_mshell(new->val, prm);
				break ;
			}
			else
				tmp2 = tmp2->next;
		}
		if (tmp2 == 0)
			ft_env_add_last(&env, ft_one_lst(new, prm));
		new = new->next;
	}
}

void	ft_free_new(t_env *new)
{
	t_env	*tmp;

	while (new != 0)
	{
		tmp = new;
		new = new->next;
		free(tmp->name);
		free(tmp->sep);
		free(tmp->val);
		free(tmp);
	}
}

int	ft_build_export(t_cmd *cmd, t_prm *prm)
{
	t_env	*new;
	int		i;

	prm->er_num = 0;
	i = 0;
	new = NULL;
	if (cmd->cmd[1] == 0)
		return (if_not_cmd1(prm->envptr));
	while (cmd->cmd[++i] != 0)
	{
		if (ft_isalpha(cmd->cmd[i][0]) != 0)
			ft_env_add_last(&new, ft_env_new(cmd->cmd[i], prm));
		else
		{
			prm->er_num = 1;
			write(2, "export: `", 9);
			write(2, cmd->cmd[i], ft_strlen(cmd->cmd[i]));
			write(2, "': not a valid identifier\n", 26);
		}
	}
	ft_search_dups(prm->envptr, new, prm);
	ft_free_new(new);
	return (prm->er_num);
}
