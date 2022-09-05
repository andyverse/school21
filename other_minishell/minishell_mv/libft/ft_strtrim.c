#include "libft.h"

static	int	cmp_set(char const c, char const *set)
{
	int	j;

	j = 0;
	while (set[j])
	{
		if (set[j] == c)
			return (1);
		j++;
	}
	return (0);
}

static char	*ft_copy(char const *s1, size_t res_len, int add, size_t res1)
{
	size_t	i;
	char	*res;

	res = (char *)malloc(sizeof(char) * (res_len + add));
	if (!res)
		return (0);
	i = 0;
	while ((i <= res_len) && (add > 1))
		res[i++] = s1[res1++];
	res[i] = 0;
	return (res);
}

void	*malloc(size_t size);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	res_len;
	size_t	res1;
	int		add;

	if (!s1 || !set)
		return (0);
	res_len = 0;
	add = 1;
	i = 0;
	while (s1[i] && cmp_set(s1[i], set))
		i++;
	res1 = i;
	if (s1[i])
	{
		i = ft_strlen(s1) - 1;
		while (s1[i] && cmp_set(s1[i], set) && res1 < i)
			i--;
		res_len = i - res1;
		add = 2;
	}
	return (ft_copy(s1, res_len, add, res1));
}
