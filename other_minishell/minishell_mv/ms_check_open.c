#include "minishell.h"

static int	ft_err_open(int er_num, char *str, t_prm *prm)
{
	char	*error_msg;

	error_msg = strerror(er_num);
	prm->er_num = er_num;
	write(2, str, ft_strlen(str));
	write(2, ": ", 2);
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
	return (1);
}

static int	ft_check_file(t_redir *tmp, t_prm *prm)
{
	int	fd;

	if (tmp->frst == 0 && tmp->scnd != 0)
	{
		fd = open(tmp->name, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			return (ft_err_open(errno, tmp->name, prm));
	}
	else if (tmp->frst == 0 && tmp->scnd == 0)
	{
		fd = open(tmp->name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			return (ft_err_open(errno, tmp->name, prm));
	}
	else
	{
		fd = open(tmp->name, O_RDONLY);
		if (fd == -1)
			return (ft_err_open(errno, tmp->name, prm));
	}
	close(fd);
	return (0);
}

int	ft_pre_open(t_prm *prm)
{
	t_redir	*tmp;

	tmp = prm->redir;
	while (tmp != NULL)
	{
		if (tmp->frst == 0 || tmp->scnd == 0)
		{
			if (ft_check_file(tmp, prm) != 0)
				return (1);
		}
		else
			ft_heredoc(tmp->name, tmp->stop, prm);
		tmp = tmp->next;
	}
	return (0);
}
