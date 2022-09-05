/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_NEW.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:30:31 by fnochiza          #+#    #+#             */
/*   Updated: 2022/05/27 00:14:50 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	assign_index(int size, int *arr, t_list *list)
{
	int			i;
	t_list_unit	*unit;

	i = 0;
	while (i < size)
	{
		unit = list->first;
		while (unit)
		{
			if (unit->val == arr[i])
				unit->index = i;
			unit = unit->next;
		}
		i++;
	}
}

void	insert_sort(int size, int *arr, t_list *list)
{
	int			i;
	int			elem;
	int			location;
	t_list_unit	*unit;

	i = 1;
	unit = list->first;
	while (i < size)
	{
		elem = arr[i];
		location = i - 1;
		while (location >= 0 && arr[location] > elem)
		{
			arr[location + 1] = arr[location];
			location = location - 1;
		}
		arr[location + 1] = elem;
		i++;
	}
	assign_index(size, arr, list);
}

int	find_max_index(t_list *list)
{
	t_list_unit	*max;
	t_list_unit	*unit;

	unit = list->first;
	max = list->first;
	while (unit)
	{
		if (unit->index >= max->index)
			max = unit;
		unit = unit->next;
	}
	return (max->index);
}

void	assign_index2(int size, int *arr, t_list *list)
{
	int			i;
	t_list_unit	*unit;

	i = 0;
	unit = list->first;
	while (unit)
	{
		i = 0;
		while (i < size)
		{
			if (unit->val == arr[i])
			{
				unit->index = i;
				break ;
			}
			i++;
		}
		unit = unit->next;
	}
}

int	spread_range(int size)
{
	if (size == 100)
		return (15);
	else
		return (30);
}
