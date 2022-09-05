/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:33:26 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/01 17:18:33 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct unit
{
	int			point;
	int			val;
	int			index;
	struct unit	*prev;
	struct unit	*next;
}	t_list_unit;

typedef struct list
{
	int			size;
	t_list_unit	*first;
	t_list_unit	*last;
}	t_list;

void		ra(t_list *list);
void		sa(t_list *list);
void		sb(t_list *list);
void		rb(t_list *list);
void		rra(t_list *list);
void		rrb(t_list *list);
void		print_error(void);
t_list		*create_list(void);
void		del_list(t_list *list);
long int	ft_atoi(const char *str);
int			*del_last_elem(t_list *list);
int			ft_strcmp(char *s1, char *s2);
int			*del_first_elem(t_list *list);
void		rr(t_list *list_a, t_list *list_b);
void		pb(t_list *list_b, t_list *list_a);
void		pa(t_list *list_a, t_list *list_b);
void		rrr(t_list *list_a, t_list *list_b);
void		print_list(t_list *list, char name);
void		add_last_elem(t_list *list, int data);
void		add_first_elem(t_list *list, int data);
int			check_for_duplicates(int *array, int size);
t_list		*check_sort(t_list *list_a, t_list *list_b);
void		print_all_lists(t_list *list_a, t_list *list_b);

#endif