/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:55:10 by fnochiza          #+#    #+#             */
/*   Updated: 2022/03/28 23:36:33 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move_b(t_list *list_a, t_list *list_b, int val)
{
	rr_or_rrr(list_a, list_b, val);
	if (find_index(list_b, val) <= list_b->size / 2)
		while (list_b->first->val != val)
			rb(list_b, 1);
	else if (find_index(list_b, val) > list_b->size / 2)
		while (list_b->first->val != val)
			rrb(list_b, 1);
}

void	move_a(t_list *list_a, int val)
{
	int	val_a;
	int	index_a;

	val_a = find_place(list_a, val);
	index_a = find_place_index(list_a, val);
	if (index_a <= list_a->size / 2)
		while (list_a->first->val != val_a)
			ra(list_a, 1);
	else if (index_a > list_a->size / 2)
		while (list_a->first->val != val_a)
			rra(list_a, 1);
}

void	sort_3(t_list *list)
{
	int	last;
	int	first;
	int	second;

	last = list->last->val;
	first = list->first->val;
	second = list->first->next->val;
	if (second > last && last > first)
	{
		rra(list, 1);
		sa(list, 1);
	}
	else if (last > first && first > second)
		sa(list, 1);
	else if (first > last && last > second)
		ra(list, 1);
	else if (second > first && first > last)
		rra(list, 1);
	else if ((first > second && second > last) || \
		(second > last && last > first))
	{
		ra(list, 1);
		sa(list, 1);
	}
}
