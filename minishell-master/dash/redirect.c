
#include "../minishell.h"

void    redirect_from_file(t_cmd *cmd)
{
    int out;

    out = 0;
    out = open(cmd->file, O_RDONLY);
    if (out == -1)
    {
        ft_putstr_fd(PROMT, 2);
        ft_putstr_fd(cmd->file, 2);
        ft_putstr_fd(": No such file or directory\n", 2);
        // g_exit_status = 126;
        return ;
    }
    dup2(out, 0);
    close(out);
}

void	redirect_to_file(t_cmd *cmd)
{
	int	out;

	out = 0;
	// while (com->delim == 3 && com->file)
	out = open(cmd->file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (out == -1)
	{
		ft_putstr_fd(PROMT, 2);
		ft_putstr_fd(cmd->file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		// g_exit_status = 126;
		return ;
	}
	// if (com->next)
	// 	com = com->next;
	// else
	// 	break ;
	// }
	dup2(out, 1);
	close(out);
}

void	append_to_file(t_cmd *cmd)
{
	int	out;

	out = 0;
	// while (com->delim == 5 && com->file)
	out = open(cmd->file, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (out == -1)
	{
		ft_putstr_fd("Minisheldon: ", 2);
		ft_putstr_fd(cmd->file, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		// g_exit_status = 126;
		return ;
	}
	// if (com->next)
	// 	com = com->next;
	// else
	// 	break ;
	// }
	dup2(out, 1);
	close(out);
}

void set_redirect(t_cmd *cmd, struct t_env *c_list, int *fd)
{
    int out;

    out = 0;
    if (c_list->ind == FROM_FILE)
        redirect_from_file(cmd);
    if (c_list->ind == TO_FILE)
        redirect_to_file(cmd);
    if (c_list->ind == APPEND)
        append_to_file(cmd);
    // if (c_list->ind == HEREDOC)
    // {
    //     out = ft_heredoc(cmd);
    //     dup2(out, 0);
    //     close(out);
    //     if (com->next && com->next->delim == 1)
	// 	{
	// 		close(1);
	// 		dup2(pipefd[1], 1);
	// 		close(pipefd[1]);
	// 		close(pipefd[0]);
	// 	}
    // }
}