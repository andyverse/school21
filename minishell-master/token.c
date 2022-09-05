/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:38:16 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/22 17:27:41 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_strtrip1(char a, char const *set)
{
	int	i;
	int	g;

	i = 0;
	g = 0;
	while (set[g])
	{
		if (set[g] == a)
		{
			i = 1;
		}
		g++;
	}
	return (i);
}

void	open_dd5(int (*i), int (*x), char *s, t_env **a)
{
	open_dd2(i, x, s);
	if ((*x) == 0)
		(*a) = new_list(ft_substr(s, (*x), (*i) - (*x) + 1), 2);
	else
		add_list((*a), new_list(ft_substr(s, (*x), (*i) - (*x) + 1), 2));
	(*i) = (*i) + 1;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		b;
	char	*s2;

	if (!s1)
		return (NULL);
	i = 0;
	b = ft_strlen(s1);
	while (s1[i] && ft_strtrip1(s1[i], set) == 1)
		i++;
	while (i < b && s1[b - 1] && ft_strtrip1(s1[b - 1], set) == 1)
		b--;
	s2 = ft_substr(s1, i, b - i);
	return (s2);
}

int	check_close(char *s)
{
	char	quote;

	while (*s)
	{
		if (*s == '\'' || *s == '\"')
		{
			quote = *s;
			while (*++s && *s != quote)
				;
			if (!*s)
			{
				return (1);
			}
		}
		++s;
	}
	return (0);
}

int	ft_strncmp_env(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	if (ft_strlen(s1) == 0 || ft_strlen(s1) == 0)
		return (-1);
	while ((ptr1[i] || ptr2[i]) && i < n && ptr1[i] != ' ' && ptr1[i] != '$')
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
