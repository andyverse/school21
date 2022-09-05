/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:36:00 by fnochiza          #+#    #+#             */
/*   Updated: 2022/03/26 16:36:36 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	print_error(t_list *list)
{
	write(2, "Error\n", 6);
	del_list(list);
	exit(0);
}

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
		printf("%d ", unit->value);
		unit = unit->next;
	}
	printf("\n");
	if (!list->first)
		printf("size %c: %d\n", name, list->size);
	else
	{
		printf("first %c: %d\n", name, list->first->value);
		printf("last  %c: %d\n", name, list->last->value);
		printf("size  %c: %d\n", name, list->size);
	}
	printf("-----------------\n");
}
