/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:33:37 by fnochiza          #+#    #+#             */
/*   Updated: 2022/03/29 00:26:23 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*create_list(void)
{
	t_list	*sample;

	sample = (t_list *) malloc(sizeof(t_list));
	if (!sample)
		return (NULL);
	sample->size = 0;
	sample->first = NULL;
	sample->last = NULL;
	return (sample);
}

void	del_list(t_list *list)
{
	t_list_unit	*listunit;
	t_list_unit	*next;

	if (list == NULL)
		return ;
	listunit = list->first;
	list->size = 0;
	next = NULL;
	while (listunit)
	{
		next = listunit->next;
		free(listunit);
		listunit = next;
	}
	free(list);
	list = NULL;
}

void	add_first_elem(t_list *list, int data)
{
	t_list_unit	*sample;

	sample = (t_list_unit *) malloc(sizeof(t_list_unit));
	if (!sample)
		return ;
	sample->point = 0;
	sample->val = data;
	sample->next = list->first;
	sample->prev = NULL;
	if (list->first)
		list->first->prev = sample;
	list->first = sample;
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
