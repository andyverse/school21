#include "minishell.h"

void	ft_sig_handler(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_redisplay();
	write(1, "  \b\b", 4);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 1);
	rl_redisplay();
}

void	ft_child_signal(int signal)
{
	if (signal == SIGQUIT)
		exit(3);
	if (signal == SIGINT)
		exit(2);
}

void	ft_pipex_signal(int signal)
{
	if (signal == SIGQUIT)
		write(2, "Quit: 3\n", 8);
	if (signal == SIGINT)
		write(2, "\n", 1);
}
