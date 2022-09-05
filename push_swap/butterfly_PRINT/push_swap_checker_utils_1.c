/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 04:46:43 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/01 17:10:58 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

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

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_checknum(unsigned long long int num, int negative)
{
	if (num > 2147483647 && negative > 0)
		print_error();
	if (num > 2147483648 && negative < 0)
		print_error();
	return ((int) num * negative);
}

long int	ft_atoi(const char *str)
{
	int						i;
	int						negative;
	unsigned long long int	num;

	num = 0;
	i = 0;
	negative = 1;
	if (str[i] == '-')
	{
		negative = -negative;
		i++;
	}
	if (str[i] == '\0' || str[i] == '-' || str[i] == '+')
		print_error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0' && (str[i] < '0' || str[i] > '9'))
		print_error();
	return (ft_checknum(num, negative));
}

void	add_first_elem(t_list *list, int data)
{
	t_list_unit	*sample;

	sample = (t_list_unit *) malloc(sizeof(t_list_unit));
	if (!sample)
		return ;
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

t_list	*check_sort(t_list *list_a, t_list *list_b)
{
	t_list_unit	*unit;

	if (!list_a)
		return (NULL);
	unit = list_a->first;
	if (list_b->size == 0)
	{
		while (unit)
		{
			if (!unit->next)
				break ;
			if (unit->val > unit->next->val)
				return (NULL);
			unit = unit->next;
		}
	}
	else
		return (NULL);
	write (1, "OK\n", 3);
	return (list_a);
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
