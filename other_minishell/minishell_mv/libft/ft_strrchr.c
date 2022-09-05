#include "libft.h"

char	*ft_strrchr(const char *str, int ch)

{
	size_t	i;
	size_t	j;
	char	c;
	char	*s;

	s = (char *)str;
	c = (char)ch;
	if (c == 0)
	{
		while (*s != 0)
			s++;
		return (s);
	}
	i = 0;
	j = 0;
	while (s[i] != 0)
	{
		if (s[i] == c)
			j = i + 1;
		i++;
	}
	if (j > 0)
		return (s + j - 1);
	return (NULL);
}
