/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:12:09 by fnochiza          #+#    #+#             */
/*   Updated: 2022/03/26 16:30:28 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_white(const char c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	res;
	int	count;

	i = 0;
	res = 0;
	s = 1;
	count = 0;
	while (ft_white(str[i]))
		i++;
	if (str[i] == '-')
		s = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - 48);
		count++;
	}
	if ((count > 19 || (i >= 1 && str[i - 1] == '9' && count == 19)) && s == 1)
		return (-1);
	if ((count > 19 || (i >= 1 && str[i - 1] == '9' && count == 19)) && s == -1)
		return (0);
	return (res * s);
}

int	find_max(t_list *list, int max)
{
	t_list_unit	*unit;

	if (list->size < 1)
		return ;
	unit = list->first->value;
	max = list->first->value;
	while (unit)
	{
		if (unit->value > max)
			max = unit->value;
		unit = unit->next;
	}
	return (max);
}

int	find_min(t_list *list, int min)
{
	t_list_unit	*unit;

	if (list->size < 1)
		return ;
	unit = list->first->value;
	min = list->first->value;
	while (unit)
	{
		if (unit->value < min)
			min = unit->value;
		unit = unit->next;
	}
	return (min);
}
