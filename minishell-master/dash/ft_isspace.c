

# include "../minishell.h"

int	is_all_spaces(char *s)
{
	int	i;

	i = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (i == ft_strlen(s))
		return (1);
	return (0);
}


static int	ft_new_len(char *s)
{
	int		i;
	int	new_len;

	i = 0;
	new_len = 0;
	while (s[i])
	{
		if (s[i] == 32 && (s[i + 1] == 32 || (s[i + 1] >= 9 && s[i + 1] <= 13)))
		{
			i++;
			new_len++;
			while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
				i++;
		}
		i++;
		new_len++;
	}
	return (new_len);
}

char *del_extra_space(char *s)
{
	int		i;
	int		new_len;
	char	*res;
	
	new_len = ft_new_len(s);
	res = calloc(new_len + 1, sizeof(char));
	i = 0;
	new_len = 0;
	while (s[i])
	{
		if (s[i] == 32 && (s[i + 1] == 32 || (s[i + 1] >= 9 && s[i + 1] <= 13)))
		{
			res[new_len] = s[i];
			i++;
			new_len++;
			while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
				i++;
		}	
		res[new_len] = s[i];
		i++;
		new_len++;
	}
	res[new_len] = '\0';
	return (res);
}

// int main()
// {
// 	char *s = "1 7777        	23";
	
// 	printf("len %d\n", ft_strlen(s));
// 	char *res = del_extra_space(s);
// 	printf("%s\n", res);
// }

// int main()
// {
// 	char *s = "     				";
// 	printf("%d\n", is_all_spaces(s));
// }
