/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:52:54 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/02 21:27:16 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	change_points(t_list *list, int i, t_list_unit *desired)
{
	if (i <= list->size / 2)
		desired->point = i;
	else if (i > list->size / 2)
		desired->point = list->size - i;
}

int	points_in_a(t_list *list_a, int value)
{
	int			i;
	int			old;
	t_list_unit	*unit;
	t_list_unit	*desired;

	i = 0;
	unit = list_a->first;
	desired = list_a->first;
	old = list_a->last->val;
	while (unit)
	{
		if (unit->val == list_a->first->val)
			if (value < unit->val && value > list_a->last->val)
				desired = unit;
		if (unit->prev != NULL && value < unit->val && value > unit->prev->val)
			desired = unit;
		if (old != desired->val)
			change_points(list_a, i, desired);
		old = desired->val;
		i++;
		unit = unit->next;
	}
	return (desired->point);
}

void	calc_point(t_list *list_a, t_list *list_b)
{
	int			i;
	t_list_unit	*unit;

	i = 0;
	unit = list_b->first;
	while (unit)
	{
		if (i <= list_b->size / 2)
			unit->point = i + points_in_a(list_a, unit->val) + 1;
		else
			unit->point = points_in_a(list_a, unit->val) + 1 + list_b->size - i;
		unit = unit->next;
		i++;
	}
}

t_list_unit	*select_unit(t_list *list_a, t_list *list_b)
{
	t_list_unit	*unit;
	t_list_unit	*des;

	calc_point(list_a, list_b);
	unit = list_b->first;
	des = list_b->first;
	while (unit)
	{
		if (unit->point <= des->point)
		{
			if (unit->point == des->point && unit->val > des->val)
				des = unit;
			else if (unit->point < des->point)
				des = unit;
		}
		unit = unit->next;
	}
	return (des);
}
