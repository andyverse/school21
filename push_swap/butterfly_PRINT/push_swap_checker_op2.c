/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_op2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 05:37:57 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/01 17:18:54 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	ra(t_list *list)
{
	if (!list || list->size == 1)
		return ;
	add_last_elem(list, *del_first_elem(list));
}

void	rb(t_list *list)
{
	if (!list || list->size == 1)
		return ;
	add_last_elem(list, *del_first_elem(list));
}

void	rr(t_list *list_a, t_list *list_b)
{
	if ((!list_a || list_a->size == 1) && (!list_b || list_b->size == 1))
		return ;
	ra(list_a);
	rb(list_b);
}

void	rra(t_list *list)
{
	if (!list || list->size == 1)
		return ;
	add_first_elem(list, *del_last_elem(list));
}

void	rrb(t_list *list)
{
	if (!list || list->size == 1)
		return ;
	add_first_elem(list, *del_last_elem(list));
}
