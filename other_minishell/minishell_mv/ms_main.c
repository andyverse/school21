#include "minishell.h"

void	ft_free(char **tmp, char **tmp2, char **ch_dollar)
{
	free(*tmp);
	*tmp = NULL;
	free(*tmp2);
	*tmp2 = NULL;
	free(*ch_dollar);
	*ch_dollar = NULL;
}

int	ft_check_empty_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == 0)
		return (1);
	return (0);
}

int	ft_use_readline(char **str, t_prm *prm)
{
	signal(SIGINT, ft_sig_handler);
	signal(SIGQUIT, SIG_IGN);
	*str = readline("minishell$ ");
	if (*str == NULL)
	{
		write(1, "minishell$ exit\n", \
				ft_strlen("minishell$ exit\n"));
		rl_redisplay();
		ft_err_exit(0, NULL, prm);
	}
	if ((*str)[0] != 0)
		add_history(*str);
	if (ft_check_empty_str(*str) != 0)
	{
		free(*str);
		return (1);
	}
	return (0);
}

void	ft_make_shell(char *str, t_prm *prm)
{
	int		fd;

	ft_parsing(str, prm);
	ft_builds_set(prm->cmd);
	ft_env_list_arr(prm->envptr, &prm->env, prm);
	ft_redir_to_cmd(prm->redir, prm->cmd);
	if (ft_pre_open(prm) == 0)
	{
		prm->num = ft_cmd_counter(prm->cmd);
		if (prm->num > 1)
			ft_do_pipe(prm);
		if (prm->num == 1 && prm->cmd->build != 0)
		{
			fd = ft_build_dup(prm->cmd, prm);
			prm->er_num = ft_run_builds(prm->cmd, prm);
			ft_build_redup(fd, prm);
		}
		else if (prm->num != 1 || prm->cmd->cmd[0])
			ft_pipex(prm);
	}
}

int	main(int argc, char **argv, char **env)
{
	char	*str;
	t_prm	prm;

	(void)argv;
	ft_struct_init(&prm);
	if (argc != 1)
		ft_err_exit(1, NULL, &prm);
	ft_parse_env(env, &prm.envptr, &prm);
	ft_check_shell_lvl(&prm);
	while (1)
	{
		if (ft_use_readline(&str, &prm) == 0) //считываем команды если пусто
		{    // то цикл заново
			if (ft_preparser(str) == 1) //проверка на ошибочные символы
			{
//				write(2, "minishell: syntax error near unexpected token\n", 46);
				write(2, ERRSYNTAX, ft_strlen(ERRSYNTAX));
				prm.er_num = 258;
			}
			else
				ft_make_shell(str, &prm);
			ft_free_str(&prm, str);
		}
	}
	ft_err_exit(prm.er_num, NULL, &prm);
}
