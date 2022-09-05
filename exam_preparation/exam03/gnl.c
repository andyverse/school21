#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	int rd;
	int i = 0;
	char c;
	char *buf = malloc(9999);

	while ((rd = read(fd, &c, 1) > 0))
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
	return buf;
}
