/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker_utils_1.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 04:46:43 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/01 17:55:08 by fnochiza         ###   ########.fr       */
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
