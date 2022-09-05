#include "libft.h"

char	*ft_strchr(const char *str, int ch)

{
	char	c;
	char	*s;

	s = (char *)str;
	c = (char)ch;
	while (*s != c)
	{
		if (*s == 0 && c != 0)
			return (NULL);
		s++;
	}
	return (s);
}
