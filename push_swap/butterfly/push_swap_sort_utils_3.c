/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 19:55:10 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/02 21:28:33 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int	find_index2(t_list *list, int val)
{
	int			i;
	int			desired;
	t_list_unit	*unit;

	i = 0;
	unit = list->first;
	desired = 0;
	while (unit)
	{
		if (unit->index == val)
		{
			desired = unit->index;
			break ;
		}
		unit = unit->next;
		i++;
	}
	return (desired);
}
