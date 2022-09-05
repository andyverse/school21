#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len;

	if (fd >= 0 && s)
	{
		len = ft_strlen(s);
		write (fd, s, len);
	}
}
