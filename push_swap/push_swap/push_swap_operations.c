/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 00:36:17 by fnochiza          #+#    #+#             */
/*   Updated: 2022/02/13 01:15:32 by fnochiza         ###   ########.fr       */
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
	if (flag == 1)
		write (1, "sb\n", 3);
	return ;
}

void	ss(t_list *list_a, t_list *list_b)
{
	if (!list_a || !list_b)
		return ;
	if (!list_a->first->next || !list_b->first->next)
		return ;
	sa(list_a, 0);
	sb(list_b, 0);
	write(1, "ss\n", 3);
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

void	ra(t_list *list, int flag)
{
	if (!list || list->size == 1)
		return ;
	add_last_elem(list, *del_first_elem(list));
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list *list, int flag)
{
	if (!list || list->size == 1)
		return ;
	add_last_elem(list, *del_first_elem(list));
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list *list_a, t_list *list_b)
{
	if ((!list_a || list_a->size == 1) && (!list_b || list_b->size == 1))
		return ;
	ra(list_a, 0);
	rb(list_b, 0);
	write(1, "rr\n", 3);
}

void	rra(t_list *list, int flag)
{
	if (!list || list->size == 1)
		return ;
	add_first_elem(list, *del_last_elem(list));
	if (flag == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list *list, int flag)
{
	if (!list || list->size == 1)
		return ;
	add_first_elem(list, *del_last_elem(list));
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list *list_a, t_list *list_b)
{
	if ((!list_a || list_a->size == 1) && (!list_b || list_b->size == 1))
		return ;
	rra(list_a, 0);
	rrb(list_b, 0);
	write(1, "rrr\n", 4);
}
