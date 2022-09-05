/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:34:49 by fnochiza          #+#    #+#             */
/*   Updated: 2022/05/23 18:21:10 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
