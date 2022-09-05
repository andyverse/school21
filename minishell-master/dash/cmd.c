# include "../minishell.h"

char	*find_path(char **envp)
{
	while (*envp && ft_strncmp("PATH", *envp, 4))
		envp++;
	if (!*envp)
	{
        ft_putstr_fd("FIND_PATH ERROR\n", 2);//redo out for particular cmd
		exit (1);
	}
	return (*envp + 5);
}

t_cmd *init_cmd(char **envp)
{
    t_cmd *cmd;

    cmd = malloc(sizeof(t_cmd));
    cmd->paths = find_path(envp);
    cmd->is_pipe = 0; //set default as 0; 1 if pipe
    cmd->p = ft_count_words(cmd->paths, ':'); //cmd->p - это количество путей в path
    cmd->cmd_paths = ft_split(cmd->paths, ':'); //free
    cmd->env = envp;
    cmd->exitstatus = 0;
    // cmd->left_pipe = NULL;
    // cmd->str = NULL;

    // int i = -1;
    // while (++i < cmd->p)
    //     printf("%s\n", cmd->cmd_paths[i]);
    return (cmd);
}

// typedef struct s_redirect
// {
// 	char	**args;//pipe_args[i]
// 	char	**exec_path;//exec_pipe[i]
// 	int		type;
// 	char	*file;

// }t_redirect;

void init_redirect_struct(t_cmd *cmd)
{
    t_redirect *r;

    
}