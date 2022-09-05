/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:12:09 by fnochiza          #+#    #+#             */
/*   Updated: 2022/03/28 20:33:56 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

int	find_max(t_list *list)
{
	int			max;
	t_list_unit	*unit;

	unit = list->first;
	max = list->first->val;
	while (unit)
	{
		if (unit->val > max)
			max = unit->val;
		unit = unit->next;
	}
	return (max);
}

int	find_min(t_list *list)
{
	int			min;
	t_list_unit	*unit;

	unit = list->first;
	min = list->first->val;
	while (unit)
	{
		if (unit->val < min)
			min = unit->val;
		unit = unit->next;
	}
	return (min);
}
