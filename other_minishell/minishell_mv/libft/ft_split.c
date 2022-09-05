#include "libft.h"

void	*malloc(size_t size);

static	char	**free_ptrs(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
	return (0);
}

static	char	**mlc_main(char const *s, char c)
{
	size_t	i;
	size_t	words;
	char	**ptr0;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	ptr0 = (char **)malloc(sizeof(char *) * (words + 1));
	return (ptr0);
}

static	char	mlc_words(char const *s, char c, char **ptr)
{
	size_t	i;
	size_t	word;
	size_t	start;
	size_t	j;

	i = -1;
	word = 0;
	while (s[++i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			word++;
			ptr[word - 1] = (char *)malloc(sizeof(char) * (i - start + 2));
			if (ptr[word - 1] == 0)
				return (0);
			j = 0;
			while (start <= i)
				ptr[word - 1][j++] = s[start++];
			ptr[word - 1][j] = '\0';
		}
	}
	ptr[word] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char	control;

	if (!s)
		return (0);
	ptr = mlc_main(s, c);
	if (!ptr)
		return (0);
	control = mlc_words(s, c, ptr);
	if (!control)
		return (free_ptrs(ptr));
	return (ptr);
}
