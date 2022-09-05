/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:50:31 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/02 21:13:55 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*check_sort(t_list *list, int size)
{
	t_list_unit	*unit;

	if (!list)
		return (NULL);
	unit = list->first;
	if (!list->first)
		return (NULL);
	if (size != list->size)
		return (NULL);
	while (unit)
	{
		if (!unit->next)
			break ;
		if (unit->val > unit->next->val)
			return (NULL);
		unit = unit->next;
	}
	return (list);
}

int	middle_value(t_list *list)
{
	int			i;
	t_list_unit	*unit;

	i = 0;
	unit = list->first;
	while (i < list->size / 2)
	{
		unit = unit->next;
		i++;
	}
	return (unit->val);
}

int	find_place(t_list *list_a, int val)
{
	t_list_unit	*unit;
	t_list_unit	*desired;

	unit = list_a->first;
	while (unit)
	{
		if (unit->val == list_a->first->val)
			if (val < unit->val && val > list_a->last->val)
				desired = unit;
		if (unit->prev != NULL && val < unit->val && val > unit->prev->val)
			desired = unit;
		unit = unit->next;
	}
	return (desired->val);
}

int	find_place_index(t_list *list_a, int val)
{
	int			i;
	int			desired;
	t_list_unit	*unit;

	i = 0;
	unit = list_a->first;
	while (unit)
	{
		if (unit->val == list_a->first->val)
			if (val < unit->val && val > list_a->last->val)
				desired = i;
		if (unit->prev != NULL && val < unit->val && val > unit->prev->val)
			desired = i;
		unit = unit->next;
		i++;
	}
	return (desired);
}

int	find_index(t_list *list, int val)
{
	int			i;
	int			desired;
	t_list_unit	*unit;

	i = 0;
	unit = list->first;
	desired = 0;
	while (unit)
	{
		if (unit->val == val)
		{
			desired = i;
			break ;
		}
		unit = unit->next;
		i++;
	}
	return (desired);
}
