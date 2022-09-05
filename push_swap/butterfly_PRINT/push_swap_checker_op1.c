/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_op1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 05:37:53 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/01 17:19:09 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	sa(t_list *list)
{
	t_list_unit	*unit1;
	t_list_unit	*unit2;

	if (!list)
		return ;
	if (!list->first->next)
		return ;
	unit1 = list->first;
	unit2 = list->first->next;
	unit1->next = unit2->next;
	unit1->prev = unit2;
	unit2->next = list->first;
	unit2->prev = NULL;
	list->first = unit2;
	if (list->size == 2)
		list->last = unit1;
	else if (list->size == 1)
		list->last = list->first;
}

void	sb(t_list *list)
{
	t_list_unit	*unit1;
	t_list_unit	*unit2;

	if (!list)
		return ;
	if (!list->first->next)
		return ;
	unit1 = list->first;
	unit2 = list->first->next;
	unit1->next = unit2->next;
	unit1->prev = unit2;
	unit2->next = list->first;
	unit2->prev = NULL;
	list->first = unit2;
	if (list->size == 2)
		list->last = unit1;
	else if (list->size == 1)
		list->last = list->first;
}

void	pa(t_list *list_a, t_list *list_b)
{
	if (!list_b)
		return ;
	add_first_elem(list_a, *del_first_elem(list_b));
}

void	pb(t_list *list_b, t_list *list_a)
{
	if (!list_a)
		return ;
	add_first_elem(list_b, *del_first_elem(list_a));
}

void	rrr(t_list *list_a, t_list *list_b)
{
	if ((!list_a || list_a->size == 1) && (!list_b || list_b->size == 1))
		return ;
	rra(list_a);
	rrb(list_b);
}
