#include "minishell.h"

void	ft_del_env(t_env *env)
{
	t_env	*tmp;

	tmp = env->next;
	env->next = tmp->next;
	free(tmp->name);
	free(tmp->sep);
	free(tmp->val);
	free(tmp);
}

int	ft_check_first(t_env **env, char *str)
{
	t_env	*tmp;

	tmp = *env;
	if (ft_strcmp(str, tmp->name) == 0)
	{
		*env = (*env)->next;
		free(tmp->name);
		free(tmp->sep);
		free(tmp->val);
		free(tmp);
		return (1);
	}
	return (0);
}

int	ft_build_unset(t_cmd *cmd, t_prm *prm)
{
	int		i;
	t_env	*tmp1;
	t_env	*tmp2;

	i = 0;
	while (cmd->cmd[++i])
	{
		if (prm->envptr == NULL)
			break ;
		if (cmd->cmd[i][0] == '_')
			continue ;
		if (ft_check_first(&prm->envptr, cmd->cmd[i]) != 0)
			continue ;
		tmp1 = prm->envptr;
		tmp2 = tmp1->next;
		while (tmp2 != 0 && ft_strcmp(cmd->cmd[i], tmp2->name) != 0)
		{
			tmp1 = tmp2;
			tmp2 = tmp2->next;
		}
		if (tmp2 != 0)
			ft_del_env(tmp1);
	}
	return (0);
}

char	*ft_get_cd(t_cmd *cmd, t_env *env, t_prm *prm)
{
	char	*pwd;
	char	*cd;

	cd = NULL;
	if (cmd->cmd[1][0] != '~')
	{
		cd = getcwd(NULL, 0);
		if (cd == 0)
			ft_err_exit(errno, "getcwd", prm);
		pwd = ft_strjoin_mshell(cd, "/", prm);
		free(cd);
		cd = ft_strjoin_mshell(pwd, cmd->cmd[1], prm);
		free(pwd);
		return (cd);
	}
	while (env != 0 && ft_strcmp(env->name, "HOME") != 0)
		env = env->next;
	if (env != 0)
	{
		pwd = ft_substr_mshell(cmd->cmd[1], 1, \
                ft_strlen(cmd->cmd[1]) - 1, prm);
		cd = ft_strjoin_mshell(env->val, pwd, prm);
		free(pwd);
	}
	return (cd);
}

int	ft_build_cd(t_cmd *cmd, t_env *env, t_prm *prm)
{
	char	*cd;

	cd = NULL;
	if (cmd->cmd[1] == 0)
	{
		while (env != 0 && ft_strcmp(env->name, "HOME") != 0)
			env = env->next;
		if (env != 0)
			cd = ft_strdup_mshell(env->val, prm);
	}
	else
		cd = ft_get_cd(cmd, env, prm);
	if (cd == 0)
	{
		write(2, "cd: HOME not set\n", 17);
		return (1);
	}
	chdir(cd);
	prm->er_num = errno;
	free(cd);
	return (prm->er_num);
}
