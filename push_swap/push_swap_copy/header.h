/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 19:19:08 by fnochiza          #+#    #+#             */
/*   Updated: 2022/03/26 16:31:09 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct unit
{
	int			index;
	int			value;
	struct unit	*prev;
	struct unit	*next;
}	t_list_unit;

typedef struct list
{
	int			size;
	t_list_unit	*first;
	t_list_unit	*last;
}	t_list;

t_list		*create_list(void);
void		print_unit(int value);
void		del_list(t_list *list);
int			ft_atoi(const char *str);
int			print_error(t_list *list);
void		sa(t_list *list, int flag);
void		sb(t_list *list, int flag);
void		ra(t_list *list, int flag);
void		rb(t_list *list, int flag);
void		rra(t_list *list, int flag);
void		rrb(t_list *list, int flag);
int			*del_last_elem(t_list *list);
int			*del_first_elem(t_list *list);
int			find_max(t_list *list, int max);
int			find_min(t_list *list, int min);
void		rr(t_list *list_a, t_list *list_b);
void		pa(t_list *list_a, t_list *list_b);
void		pb(t_list *list_b, t_list *list_a);
void		ss(t_list *list_a, t_list *list_b);
void		rrr(t_list *list_a, t_list *list_b);
void		print_list(t_list *list, char name);
void		delete_unit(t_list *list, int index);
void		add_last_elem(t_list *list, int data);
void		add_first_elem(t_list *list, int data);
t_list_unit	*get_index_elem(t_list *list, int index);
void		insert(t_list *list, int index, int value);

#endif
