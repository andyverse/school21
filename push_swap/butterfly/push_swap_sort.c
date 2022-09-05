/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_NEW_SORT.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:40:56 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/02 21:20:03 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fly_in_b(t_list *list_a, t_list *list_b, int size, int *array)
{
	int			counter;

	counter = 0;
	(void) size;
	(void) array;
	while (list_a->size > 0)
	{
		if (list_a->first->index <= counter)
		{
			pb(list_b, list_a);
			rb(list_b, 1);
			counter++;
		}
		else if (list_a->first->index <= counter + spread_range(size))
		{
			pb(list_b, list_a);
			counter++;
		}
		else
		{
			ra(list_a, 1);
			assign_index2(size, array, list_a);
		}
	}
}

void	fly_in_a(t_list *list_a, t_list *list_b)
{
	while (list_b->size > 0)
	{
		if (find_index(list_b, find_max(list_b)) <= list_b->size / 2)
		{
			while (list_b->first->val != find_max(list_b))
				rb(list_b, 1);
			pa(list_a, list_b);
		}
		else if (find_index(list_b, find_max(list_b)) > list_b->size / 2)
		{
			while (list_b->first->val != find_max(list_b))
				rrb(list_b, 1);
			pa(list_a, list_b);
		}
	}
}
