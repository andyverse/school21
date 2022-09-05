/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_utlis_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:46:27 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/01 17:51:01 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	add_last_elem(t_list *list, int data)
{
	t_list_unit	*sample;

	if (list->size == 0)
	{
		add_first_elem(list, data);
		return ;
	}
	sample = (t_list_unit *) malloc(sizeof(t_list_unit));
	if (!sample)
		return ;
	sample->val = data;
	sample->prev = list->last;
	sample->next = NULL;
	if (list->last)
		list->last->next = sample;
	list->last = sample;
	if (list->last == NULL)
		list->last = sample;
	list->size++;
}

int	*del_first_elem(t_list *list)
{
	int			*returned;
	t_list_unit	*sample;

	if (!list)
		return (NULL);
	sample = list->first;
	list->first = list->first->next;
	if (list->first)
		list->first->prev = NULL;
	if (sample == list->last)
		list->last = NULL;
	returned = &sample->val;
	list->size--;
	free(sample);
	return (returned);
}

int	*del_last_elem(t_list *list)
{
	int			*returned;
	t_list_unit	*sample;

	if (list->last == NULL)
		return (NULL);
	sample = list->last;
	list->last = list->last->prev;
	if (list->last)
		list->last->next = NULL;
	if (list->first == sample)
		list->first = NULL;
	returned = &sample->val;
	free(sample);
	list->size--;
	return (returned);
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

int	check_for_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size - 1)
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}