/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_utils_3.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:53:56 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/01 18:08:02 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

t_list	*check_sort(t_list *list_a, t_list *list_b)
{
	t_list_unit	*unit;

	if (!list_a)
		return (NULL);
	unit = list_a->first;
	if (list_b->size == 0)
	{
		while (unit)
		{
			if (!unit->next)
				break ;
			if (unit->val > unit->next->val)
				return (NULL);
			unit = unit->next;
		}
	}
	else
		return (NULL);
	write (1, "OK\n", 3);
	return (list_a);
}

void	del_list(t_list *list)
{
	t_list_unit	*listunit;
	t_list_unit	*next;

	if (list == NULL)
		return ;
	listunit = list->first;
	list->size = 0;
	next = NULL;
	while (listunit)
	{
		next = listunit->next;
		free(listunit);
		listunit = next;
	}
	free(list);
	list = NULL;
}

char	*ft_strjoin(char *str, char c)
{
	int		i;
	char	*s;

	i = 0;
	while (str[i] != '\0')
		i++;
	s = (char *)malloc(i + 2);
	if (!s)
		print_error();
	i = 0;
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i++] = c;
	s[i] = '\0';
	free(str);
	return (s);
}

int	get_next_line(char **str)
{
	int		flag;
	char	c;

	*str = (char *)malloc(1);
	if (!*str)
		print_error();
	*str[0] = '\0';
	flag = 1;
	while (flag > 0)
	{
		flag = read(0, &c, 1);
		if (c == '\n')
			break ;
		*str = ft_strjoin(*str, c);
	}
	return (flag);
}
