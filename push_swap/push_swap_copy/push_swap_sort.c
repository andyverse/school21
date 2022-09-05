/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 02:55:46 by fnochiza          #+#    #+#             */
/*   Updated: 2022/03/26 16:34:14 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*check_sort(t_list *list, int size)
{
	t_list_unit	*unit;

	if (!list)
		return (NULL);
	if (!list->first)
		return (NULL);
	if (size != list->size)
		return (NULL);
	while (unit)
	{
		if (!unit->next)
			break ;
		if (unit->value > unit->next->value)
			return (NULL);
		unit = unit->next;
	}
	return (list);
}

void pushing_a(t_list *list_a, t_list *list_b)
{
	t_list_unit *unit1;
	t_list_unit *unit2;
	
}
