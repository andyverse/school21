/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:36:17 by fnochiza          #+#    #+#             */
/*   Updated: 2022/03/28 21:33:12 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sa(t_list *list, int flag)
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
	if (flag == 1)
		write (1, "sa\n", 3);
}

void	sb(t_list *list, int flag)
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
	if (flag == 1)
		write (1, "sb\n", 3);
}

void	pa(t_list *list_a, t_list *list_b)
{
	if (!list_b)
		return ;
	add_first_elem(list_a, *del_first_elem(list_b));
	write(1, "pa\n", 3);
}

void	pb(t_list *list_b, t_list *list_a)
{
	if (!list_a)
		return ;
	add_first_elem(list_b, *del_first_elem(list_a));
	write(1, "pb\n", 3);
}

void	rrr(t_list *list_a, t_list *list_b)
{
	if ((!list_a || list_a->size == 1) && (!list_b || list_b->size == 1))
		return ;
	rra(list_a, 0);
	rrb(list_b, 0);
	write(1, "rrr\n", 4);
}
