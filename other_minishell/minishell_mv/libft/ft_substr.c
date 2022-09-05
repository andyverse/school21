#include "libft.h"

void	*malloc(size_t size);

char	*ft_substr(char const *s1, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	if (!s1)
		return (0);
	i = 0;
	while (s1[i++] != 0)
		;
	if (start >= i)
		len = 0;
	else if (i - start < len)
		len = i - start;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		s2[i] = s1[start + i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}
