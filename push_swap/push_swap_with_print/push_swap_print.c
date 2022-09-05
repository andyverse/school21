/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:36:00 by fnochiza          #+#    #+#             */
/*   Updated: 2022/03/28 20:34:41 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// int	print_error(t_list *list)
// {
// 	write(2, "Error\n", 6);
// 	del_list(list);
// 	exit(0);
// }

void	print_list(t_list *list, char name)
{
	t_list_unit	*unit;

	if (!list)
		return ;
	unit = list->first;
	printf("-----------------\n");
	printf("list_%c -> ", name);
	while (unit)
	{
		printf("%d ", unit->val);
		unit = unit->next;
	}
	printf("\n");
	if (!list->first)
		printf("size %c: %d\n", name, list->size);
	else
	{
		printf("first %c: %d\n", name, list->first->val);
		printf("last  %c: %d\n", name, list->last->val);
		printf("size  %c: %d\n", name, list->size);
	}
	printf("-----------------\n");
}

void	print_all_lists(t_list *list_a, t_list *list_b)
{
	t_list_unit	*unit;

	if (!list_a)
		return ;
	unit = list_a->first;
	printf("-----------------\n");
	printf("list_a -> ");
	while (unit)
	{
		printf("%d ", unit->val);
		unit = unit->next;
	}
	printf("\n");
	if (!list_b)
		return ;
	unit = list_b->first;
	printf("list_b -> ");
	while (unit)
	{
		printf("%d ", unit->val);
		unit = unit->next;
	}
	printf("\n");
	printf("-----------------\n");
}

void	print_score(t_list *list_a, t_list *list_b)
{
	t_list_unit	*unit;

	if (!list_a)
		return ;
	unit = list_a->first;
	calc_point(list_a, list_b);
	printf("-----------------\n");
	printf("list_a -> ");
	while (unit)
	{
		printf("%d ", unit->val);
		unit = unit->next;
	}
	printf("\n");
	if (!list_b)
		return ;
	unit = list_b->first;
	printf("list_b -> ");
	while (unit)
	{
		printf("%3d ", unit->val);
		unit = unit->next;
	}
	printf("\n");
	printf("score  -> ");
	unit = list_b->first;
	while (unit)
	{
		printf("%3d ", unit->point);
		unit = unit->next;
	}
	printf("\n");
	printf("-----------------\n");
}
