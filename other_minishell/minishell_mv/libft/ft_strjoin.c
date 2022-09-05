#include "libft.h"

void	*malloc(size_t size);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	len;
	char	*s3;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char *)malloc(sizeof(char) * (len + 1));
	if (s3 == NULL)
		return (0);
	i = 0;
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		s3[i] = *s2++;
		i++;
	}
	s3[i] = 0;
	return (s3);
}
