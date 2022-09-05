#include "minishell.h"

int	ft_strcmp(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] || str2[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup_mshell(const char *s1, t_prm *prm)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s1) + 1;
	str = malloc(len * sizeof(*str));
	if (str == NULL)
		ft_err_exit(errno, "malloc", prm);
	str = ft_memmove(str, s1, len);
	return (str);
}

char	*ft_strjoin_mshell(char const *s1, char const *s2, t_prm *prm)
{
	int		i;
	int		j;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = (int)ft_strlen(s1) + (int)ft_strlen(s2) + 1;
	str = malloc(i * sizeof(*str));
	if (str == NULL)
		ft_err_exit(errno, "malloc", prm);
	i = 0;
	j = 0;
	while (s1[j] != 0)
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != 0)
		str[i++] = s2[j++];
	str[i] = 0;
	return (str);
}

char	*ft_substr_mshell(char const *s, unsigned start, \
		size_t len, t_prm *prm)
{
	int		i;
	char	*substr;

	if (s == NULL)
		return (NULL);
	substr = malloc((len + 1) * sizeof(*substr));
	if (substr == NULL)
		ft_err_exit(errno, "malloc", prm);
	i = 0;
	if (start < ft_strlen(s))
	{
		len = len + start;
		while (s[start] != 0 && start < len)
			substr[i++] = s[start++];
	}
	substr[i] = 0;
	return (substr);
}
