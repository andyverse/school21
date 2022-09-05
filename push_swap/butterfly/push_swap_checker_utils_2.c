/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_utils_2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:46:27 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/01 18:46:23 by fnochiza         ###   ########.fr       */
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

void	check_result(t_list *stack, t_list *stack_b)
{
	t_list_unit	*tmp;

	tmp = stack->first;
	if (stack_b->first == NULL)
	{
		while (tmp->next != NULL)
		{
			if (tmp->val > tmp->next->val)
			{
				write (0, "KO\n", 3);
				exit(0);
			}
			tmp = tmp->next;
		}
		write (0, "OK\n", 3);
		exit(0);
	}
	write (1, "KO\n", 3);
}
