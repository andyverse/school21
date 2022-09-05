/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:34:49 by fnochiza          #+#    #+#             */
/*   Updated: 2022/03/26 16:35:34 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_last_elem(t_list *list, int data)
{
	t_list_unit	*sample;

	sample = (t_list_unit *) malloc(sizeof(t_list_unit));
	if (!sample)
		return ;
	sample->value = data;
	sample->prev = list->last;
	sample->next = NULL;
	if (list->last)
		list->last->next = sample;
	list->last = sample;
	if (list->last == NULL)
		list->last = sample;
	list->size++;
}

int	*del_last_elem(t_list *list)
{
	int			*returned;
	t_list_unit	*sample;

	if (list->last == NULL)
		return (NULL);
	sample = (t_list_unit *) malloc(sizeof(t_list_unit));
	if (!sample)
		return (NULL);
	sample = list->last;
	list->last = list->last->prev;
	if (list->last)
		list->last->next = NULL;
	if (list->first == sample)
		list->first = NULL;
	returned = &sample->value;
	free(sample);
	list->size--;
	return (returned);
}

t_list_unit	*get_index_elem(t_list *list, int index)
{
	int			i;
	t_list_unit	*sample;

	sample = NULL;
	if (index > list->size / 2)
	{
		sample = list->last;
		i = list->size - 1;
		while (sample && i > index)
		{
			sample = sample->prev;
			i--;
		}
	}
	else
	{
		sample = list->first;
		i = 0;
		while (sample && i < index)
		{
			sample = sample->next;
			i++;
		}
	}
	return (sample);
}

void	insert(t_list *list, int index, int value)
{
	t_list_unit	*current_unit;
	t_list_unit	*insert_unit;

	insert_unit = (t_list_unit *) malloc(sizeof(t_list_unit));
	current_unit = get_index_elem(list, index);
	if (!current_unit)
		return ;
	insert_unit->value = value;
	insert_unit->prev = current_unit;
	insert_unit->next = current_unit->next;
	if (current_unit->next)
		current_unit->next->prev = insert_unit;
	current_unit->next = insert_unit;
	if (!insert_unit->next)
		list->last = insert_unit;
	list->size++;
}

void	delete_unit(t_list *list, int index)
{
	t_list_unit	*current_unit;

	current_unit = get_index_elem(list, index);
	if (!current_unit)
		return ;
	if (current_unit->prev)
		current_unit->prev->next = current_unit->next;
	if (current_unit->next)
		current_unit->next->prev = current_unit->prev;
	if (!current_unit->next)
		list->last = current_unit->prev;
	if (!current_unit->prev)
		list->first = current_unit->next;
	free(current_unit);
	list->size--;
}

void	insert_before_elem(t_list *list, t_list_unit *unit, int value)
{
	t_list_unit	*insert_unit;

	if (!unit)
		return ;
	if (!unit->prev)
	{
		add_first_elem(list, value);
		return ;
	}
	insert_unit = (t_list_unit *) malloc(sizeof(t_list_unit));
	insert_unit->value = value;
	insert_unit->prev = unit->prev;
	unit->prev->next = insert_unit;
	insert_unit->next = unit;
	unit->prev = insert_unit;
	list->size++;
}
