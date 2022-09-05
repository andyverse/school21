/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:40:02 by fnochiza          #+#    #+#             */
/*   Updated: 2022/04/08 18:52:18 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	pushing_b(t_list *list_a, t_list *list_b, int min_a, int max_a)
{
	while (list_a->size > 2)
	{
		if (list_a->first->val == max_a || list_a->first->val == min_a)
			ra(list_a, 1);
		if (list_a->first->val == max_a || list_a->first->val == min_a)
			ra(list_a, 1);
		pb(list_b, list_a);
		if (list_b->size > 0)
		{
			if (list_b->first->val < middle_value(list_b) && \
			(list_a->first->val == min_a || list_a->first->val == max_a))
				rr(list_a, list_b);
			else if (list_b->first->val < middle_value(list_b))
				rb(list_b, 1);
		}
	}
	if (list_a->first->val == min_a)
		sa(list_a, 1);
}

void	pushing_a(t_list *list_a, t_list *list_b)
{
	int			i;
	t_list_unit	*unit;

	i = 0;
	while (list_b->size > 0)
	{
		unit = select_unit(list_a, list_b);
		move_b(list_a, list_b, unit->val);
		move_a(list_a, unit->val);
		pa(list_a, list_b);
		i++;
	}
}

void	finish_sort(t_list *list_a)
{
	int	min;

	min = find_min(list_a);
	if (find_index(list_a, min) <= list_a->size / 2)
		while (list_a->first->val != min)
			ra(list_a, 1);
	else if (find_index(list_a, min) > list_a->size / 2)
		while (list_a->first->val != min)
			rra(list_a, 1);
}

void	sort_3_elem(t_list *list)
{
	int	last;
	int	first;
	int	second;

	if (list->size < 2)
		return ;
	last = list->last->val;
	first = list->first->val;
	if (list->size == 2 && last > first)
		sb(list, 1);
	else if (list->size != 3)
		return ;
	second = list->first->next->val;
	if (first > second && second > last)
		return ;
	else if (second > first && first > last)
		sb(list, 1);
	else if (second > last && last > first)
		rb(list, 1);
	else if (last > first && first > second)
		rrb(list, 1);
}

void	minisort(t_list *la, t_list *lb)
{
	int	sec;

	while (la->size > 2)
	{
		sec = la->first->next->val;
		if (la->first->val <= sec && la->first->val < la->last->val)
			pb(lb, la);
		else if (sec <= la->first->val && la->first->val <= la->last->val)
			sa(la, 1);
		else if (sec <= la->last->val && sec <= la->first->val)
			sa(la, 1);
		else if (la->last->val <= la->first->val && la->last->val < sec)
			rra(la, 1);
		sort_3_elem(lb);
	}
	if (la->first->val > la->last->val)
		sa(la, 1);
	while (lb->size > 0)
		pa(la, lb);
	finish_sort(la);
}
