#include "minishell.h"

void	ft_do_pipe(t_prm *prm)
{
	int	i;

	prm->fd = malloc((prm->num - 1) * sizeof(int *));
	if (prm->fd == NULL)
		ft_err_exit(errno, "malloc", prm);
	i = -1;
	while (++i < prm->num - 1)
	{
		prm->fd[i] = malloc(2 * sizeof(int));
		if (prm->fd[i] == NULL)
			ft_err_exit(errno, "malloc", prm);
		if (pipe(prm->fd[i]) == -1)
		{
			prm->er_num = errno;
			while (i-- != 0)
			{
				close(prm->fd[i][0]);
				close(prm->fd[i][1]);
			}
			ft_err_exit(prm->er_num, "pipe", prm);
		}
	}
}
