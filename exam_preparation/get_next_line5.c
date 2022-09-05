#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	int rd;
	int i = 0;
	char c;
	char	*buf = malloc(9999);

	while (rd = read())
}