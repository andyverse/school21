#include "libft.h"

void	*malloc(size_t size);

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;

	i = 0;
	while (s1[i++] != 0)
		;
	s2 = (char *)malloc(i);
	if (s2 == NULL)
		return (0);
	i = 0;
	while (s1[i] != 0)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = s1[i];
	return (s2);
}
