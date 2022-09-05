/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:21:09 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/19 21:21:18 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit(int i, int j, t_game_map **map, char **map_array)
{
	int	flag;

	flag = 0;
	while (i < (*map)->height)
	{
		j = 0;
		while (j < (*map)->length)
		{
			if (ft_strchr("E", map_array[i][j]) != NULL)
				flag++;
			j++;
		}
		i++;
	}
	if (flag == 0)
	{
		ft_printf("Exit Error");
		print_error();
	}
}

void	check_bun(int i, int j, t_game_map **map, char **map_array)
{
	int	flag;

	flag = 0;
	while (i < (*map)->height)
	{
		j = 0;
		while (j < (*map)->length)
		{
			if (ft_strchr("C", map_array[i][j]) != NULL)
				flag++;
			j++;
		}
		i++;
	}
	if (flag == 0)
	{
		ft_printf("Bun Error");
		print_error();
	}
}

void	check_symbols(int i, int j, t_game_map **map, char **map_array)
{
	while (i < (*map)->height)
	{
		j = 0;
		while (j < (*map)->length)
		{
			if (ft_strchr("10CPE\n", map_array[i][j]) == NULL)
			{
				ft_printf("Sybmols Error");
				print_error();
			}
			j++;
		}
		i++;
	}
}

void	check_map(int i, int j, t_game_map **map, char **map_array)
{
	check_wall(i, j, map, map_array);
	check_player(i, j, map, map_array);
	check_exit(i, j, map, map_array);
	check_bun(i, j, map, map_array);
	check_symbols(i, j, map, map_array);
}

void	create_map(int argc, char **argv, t_game_map **map)
{
	int		i;
	int		j;
	char	**map_array;

	i = 0;
	j = 0;
	count_map_size(argv, map, 0, 0);
	ft_printf("%d %d\n", (*map)->length, (*map)->height);
	create_array(argv, map, &map_array, 0);
	print_map(0, 0, map, &map_array);
	// check_wall(i, j, map, map_array);
	// check_player(i, j, map, map_array);
	// check_exit(i, j, map, map_array);
	// check_bun(i, j, map, map_array);
	// check_symbols(i, j, map, map_array);
	// check_name(argv);
}
