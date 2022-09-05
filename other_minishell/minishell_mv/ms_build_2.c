#include "minishell.h"

static void	ft_check_minus_n(t_cmd *cmd, int *num, t_prm *prm)
{
	int	j;
	int	i;

	i = 0;
	while (cmd->cmd[++i] != 0)
	{
		if (cmd->cmd[i][0] != '-')
			break ;
		j = 1;
		while (cmd->cmd[i][j] == 'n')
			j++;
		if (cmd->cmd[i][j] != 0)
			break ;
		free(cmd->cmd[i]);
		cmd->cmd[i] = ft_strdup_mshell("-n", prm);
	}
	while (cmd->cmd[*num] != 0 && ft_strcmp(cmd->cmd[*num], "-n") == 0)
		(*num)++;
}

int	ft_build_echo(t_cmd *cmd, t_prm *prm)
{
	int	j;
	int	i;

	i = 1;
	ft_check_minus_n(cmd, &i, prm);
	j = i - 1;
	while (cmd->cmd[i] != 0)
	{
		if (cmd->cmd[i + 1])
			printf("%s ", cmd->cmd[i]);
		else
			printf("%s", cmd->cmd[i]);
		++i;
	}
	if (j == 0)
		printf("\n");
	return (0);
}

int	ft_build_env(t_env *env)
{
	t_env	*tmp;

	if (env == NULL)
		return (0);
	tmp = env;
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->sep, "=") == 0)
			printf("%s%s%s\n", tmp->name, tmp->sep, tmp->val);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_build_pwd(t_prm *prm)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		ft_err_exit(errno, "getcwd", prm);
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
