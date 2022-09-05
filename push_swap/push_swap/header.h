/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:19:08 by fnochiza          #+#    #+#             */
/*   Updated: 2022/03/28 23:43:01 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct unit
{
	int			point;
	int			val;
	struct unit	*prev;
	struct unit	*next;
}	t_list_unit;

typedef struct list
{
	int			size;
	t_list_unit	*first;
	t_list_unit	*last;
}	t_list;

void		print_error(void);
t_list		*create_list(void);
void		sort_3(t_list *list);
void		del_list(t_list *list);
int			find_max(t_list *list);
int			find_min(t_list *list);
long int	ft_atoi(const char *str);
void		sort_3_elem(t_list *list);
int			middle_value(t_list *list);
void		sa(t_list *list, int flag);
void		sb(t_list *list, int flag);
void		ra(t_list *list, int flag);
void		rb(t_list *list, int flag);
void		finish_sort(t_list *list_a);
void		rra(t_list *list, int flag);
void		rrb(t_list *list, int flag);
int			*del_last_elem(t_list *list);
int			*del_first_elem(t_list *list);
void		move_a(t_list *list_a, int val);
void		minisort(t_list *la, t_list *lb);
int			find_index(t_list *list, int val);
void		rr(t_list *list_a, t_list *list_b);
void		pa(t_list *list_a, t_list *list_b);
void		pb(t_list *list_b, t_list *list_a);
void		ss(t_list *list_a, t_list *list_b);
t_list		*check_sort(t_list *list, int size);
int			find_place(t_list *list_a, int val);
void		rrr(t_list *list_a, t_list *list_b);
void		print_list(t_list *list, char name);
void		delete_unit(t_list *list, int index);
void		add_last_elem(t_list *list, int data);
int			points_in_a(t_list *list_a, int value);
void		add_first_elem(t_list *list, int data);
t_list_unit	*get_index_elem(t_list *list, int index);
int			find_place_index(t_list *list_a, int val);
void		pushing_a(t_list *list_a, t_list *list_b);
void		insert(t_list *list, int index, int value);
void		calc_point(t_list *list_a, t_list *list_b);
t_list_unit	*select_unit(t_list *list_a, t_list *list_b);
void		move_b(t_list *list_a, t_list *list_b, int val);
void		rr_or_rrr(t_list *list_a, t_list *list_b, int val);
void		change_points(t_list *list, int i, t_list_unit *desired);
void		pushing_b(t_list *list_a, t_list *list_b, int min_a, int max_a);

#endif
