/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:17:02 by fnochiza          #+#    #+#             */
/*   Updated: 2022/03/28 23:37:37 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

t_list	*stack_initialization(int argc, char *argv[])
{
	int		i;
	int		int_value;
	t_list	*list;
	int		*array_value;

	i = 1;
	if (argc < 2)
		return (NULL);
	list = create_list();
	array_value = (int *) malloc(argc * sizeof(int));
	if (!array_value)
		return (NULL);
	while (i < argc)
	{
		int_value = ft_atoi(argv[i]);
		array_value[i - 1] = int_value;
		add_last_elem(list, int_value);
		i++;
	}
	if (check_for_duplicates(array_value, i) == 0)
		print_error();
	free(array_value);
	array_value = NULL;
	return (list);
}

t_list	*create_list_b(t_list *list)
{
	t_list		*list_b;
	t_list_unit	*unit;

	if (!list)
		return (NULL);
	unit = list->first;
	list_b = create_list();
	return (list_b);
}

int	main(int argc, char *argv[])
{
	int		min_a;
	int		max_a;
	t_list	*list_a;
	t_list	*list_b;

	if (argc < 2)
		return (0);
	list_a = stack_initialization(argc, argv);
	list_b = create_list_b(list_a);
	min_a = find_min(list_a);
	max_a = find_max(list_a);
	if (argc == 4)
		sort_3(list_a);
	else if (argc != 6)
	{
		while (list_a->size > 2)
			pushing_b(list_a, list_b, min_a, max_a);
		pushing_a(list_a, list_b);
		finish_sort(list_a);
	}
	else
		minisort(list_a, list_b);
	del_list(list_a);
	del_list(list_b);
	return (0);
}
