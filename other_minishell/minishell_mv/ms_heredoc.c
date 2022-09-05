#include "minishell.h"

static void	ft_file_write(char *name, int fd, char *line, t_prm *prm)
{
	if (write(fd, line, ft_strlen(line)) == -1)
		ft_err_exit(errno, name, prm);
	if (write(fd, "\n", 1) == -1)
		ft_err_exit(errno, name, prm);
}

static int	ft_strcmp_hdoc(const char *s1, const char *s2)
{
	int	new_str;

	new_str = 0;
	while (new_str == 0 && (*s1 != 0 || *s2 != 0))
		new_str = (unsigned char)*(s1++) - (unsigned char)*(s2++);
	return (new_str);
}

static void	ft_gnl_hdoc(char **line, t_prm *prm)
{
	char	*tmp;
	char	*last;

	*line = ft_strdup("\0");
	last = ft_strdup("\0\0");
	if (last == NULL || *line == NULL)
		ft_err_exit(12, "malloc", prm);
	while (*last != '\n')
	{
		read(0, last, 1);
		if (*last == '\n')
			break ;
		tmp = ft_strjoin(*line, last);
		if (tmp == NULL)
		{
			free(last);
			ft_err_exit(12, "malloc", prm);
		}	
		free(*line);
		*line = tmp;
	}
	free(last);
}

void	ft_heredoc(char *name, char *stop, t_prm *prm)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(name, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0644);
	if (fd == -1)
		ft_err_exit(errno, name, prm);
	i = 1;
	while (i)
	{
		write(1, "> ", 2);
		ft_gnl_hdoc(&line, prm);
		if (ft_strcmp_hdoc(line, stop))
			ft_file_write(name, fd, line, prm);
		else
			i = 0;
		free(line);
	}
	close(fd);
}
