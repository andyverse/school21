/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:12:48 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/19 19:58:14 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	struct_init(t_game_map **map)
{
	(*map)->data = NULL;
	(*map)->wall = NULL;
	(*map)->exit = NULL;
	(*map)->player = NULL;
	(*map)->bg = NULL;
	(*map)->star = NULL;
	(*map)->enemy = NULL;
	(*map)->marvin = NULL;
	(*map)->enemypos = NULL;
	(*map)->err_msg = NULL;
}

void	free_elem(void *str)
{
	free(str);
	str = NULL;
}

void	free_struct(t_game_map **map)
{
	free_elem((*map)->data);
	free_elem((*map)->wall);
	free_elem((*map)->exit);
	free_elem((*map)->player);
	free_elem((*map)->bg);
	free_elem((*map)->star);
	free_elem((*map)->enemy);
	free_elem((*map)->marvin);
	free_elem((*map)->enemypos);
	free_elem((*map)->err_msg);
	free((*map));
}

void	check_length(int bit, int length, int i)
{
	if (length != -1 && length != i)
	{
		ft_printf("%d %d %d", bit, length, i);
		print_error();
	}
}

void	count_map_size(char **argv, t_game_map **map, int i, int count)
{
	int		fd;
	int		bit;
	char	chr;

	fd = open(argv[1], O_RDONLY);
	chr = ' ';
	bit = 1;
	(*map)->length = -1;
	while (chr != '\0' && bit != 0)
	{
		bit = read(fd, &chr, 1);
		if (bit == -1)
		{
			ft_printf("Read Error\n");
			print_error();
		}
		i++;
		if (chr == '\n' || bit == 0)
		{
			check_length(bit, (*map)->length, i);
			(*map)->length = i;
			count++;
			i = 0;
		}
	}
	close(fd);
	(*map)->height = count;
}
