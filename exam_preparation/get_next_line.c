#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	*buf = malloc(9999);
	int		i = 0;
	char	c;
	int		rd = 0;

	while ((rd = read(fd, &c, 1)) > 0)
	{
		buf[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	if ((!buf[i - 1] && !rd) || rd == -1)
	{
		free(buf);
		return (NULL);
	}
	buf[i] = '\0';
	return (buf);
}