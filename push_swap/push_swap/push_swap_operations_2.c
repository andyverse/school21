/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:37:27 by fnochiza          #+#    #+#             */
/*   Updated: 2022/03/29 00:29:08 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
