/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 19:21:09 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/25 06:08:25 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit(int i, int j, t_game *map)
{
	int	flag;

	flag = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->length)
		{
			if (ft_strchr("E", map->data[i][j]) != NULL)
			{
				map->xe = j;
				map->ye = i;
				flag++;
			}
			j++;
		}
		i++;
	}
	if (flag == 0)
		print_error();
}

void	check_bun(int i, int j, t_game *map)
{
	map->buns = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->length)
		{
			if (ft_strchr("C", map->data[i][j]) != NULL)
				map->buns++;
			j++;
		}
		i++;
	}
	if (map->buns == 0)
		print_error();
}

void	check_symbols(int i, int j, t_game *map)
{
	map->zero = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->length)
		{
			if (map->data[i][j] == '0')
				map->zero++;
			if (ft_strchr("10CPE\n", map->data[i][j]) == NULL)
				print_error();
			j++;
		}
		i++;
	}
}

void	check_map(int i, int j, t_game *map, char **argv)
{
	check_wall(i, j, map);
	check_player(i, j, map);
	check_exit(i, j, map);
	check_bun(i, j, map);
	check_symbols(i, j, map);
	check_name(argv);
}

void	change_player(t_game *map, int keycode, int k)
{
	char	*img_ptr;

	img_ptr = "./sprite/t_l.xpm";
	if (keycode == 0)
	{
		move_player(map, 0, -1);
		img_ptr = "./sprite/t_l.xpm";
	}
	else if (keycode == 1)
	{
		move_player(map, 1, 0);
		img_ptr = "./sprite/t_d.xpm";
	}
	else if (keycode == 2)
	{
		move_player(map, 0, 1);
		img_ptr = "./sprite/t_r.xpm";
	}
	else if (keycode == 13)
	{
		move_player(map, -1, 0);
		img_ptr = "./sprite/t_u.xpm";
	}
	map->pl.img = mlx_xpm_file_to_image(map->mlx, img_ptr, &k, &k);
}
