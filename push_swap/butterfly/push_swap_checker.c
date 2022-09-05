/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 02:09:02 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/02 21:33:35 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// goal: for Baksel to break her head

#include "header_bonus.h"

t_list	*create_stack(int argc, char **argv)
{
	int		i;
	int		int_value;
	int		*array;
	t_list	*list;

	i = 1;
	list = create_list();
	array = (int *) malloc(argc * sizeof(int));
	while (argv[i] != NULL)
	{
		int_value = ft_atoi(argv[i]);
		array[i - 1] = int_value;
		add_last_elem(list, int_value);
		i++;
	}
	if (check_for_duplicates(array, i) == 0)
		print_error();
	return (list);
}

int	read_action(char *action)
{
	int		i;
	int		flag;
	char	c;

	i = 0;
	c = '0';
	flag = 1;
	while (flag > 0)
	{
		flag = read(0, &c, 1);
		if (c == '\n')
			break ;
		if (i < 4)
			action[i] = c;
		i++;
	}
	action[i - 1] = '\0';
	if (i >= 4)
		print_error();
	return (flag);
}

int	check_read(char **action)
{
	int	flag;

	flag = 1;
	while (flag > 0)
	{
		flag = get_next_line(action);
		if (flag == -1)
			print_error();
		if (flag == 1)
			break ;
	}
	return (flag);
}

void	check_action(t_list *stack_a, t_list *stack_b, char *action)
{
	if (ft_strcmp(action, "sa"))
		sa(stack_a);
	else if (ft_strcmp(action, "sb"))
		sb(stack_b);
	else if (ft_strcmp(action, "ra"))
		ra(stack_a);
	else if (ft_strcmp(action, "rb"))
		rb(stack_b);
	else if (ft_strcmp(action, "rra"))
		rra(stack_a);
	else if (ft_strcmp(action, "rrb"))
		rrb(stack_b);
	else if (ft_strcmp(action, "pb"))
		pb(stack_b, stack_a);
	else if (ft_strcmp(action, "pa"))
		pa(stack_a, stack_b);
	else if (ft_strcmp(action, "rr"))
		rr(stack_a, stack_b);
	else if (ft_strcmp(action, "rrr"))
		rrr(stack_a, stack_b);
	else
		print_error();
}

int	main(int argc, char **argv)
{
	char	*action;
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2)
		exit(1);
	action = NULL;
	stack_a = create_stack(argc, argv);
	stack_b = create_list();
	while (check_read(&action) > 0)
	{
		if (*action == '\0')
			print_error();
		check_action(stack_a, stack_b, action);
		free(action);
	}
	check_result(stack_a, stack_b);
	del_list(stack_a);
	del_list(stack_b);
}
