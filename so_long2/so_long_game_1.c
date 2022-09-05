/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:54:55 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/25 06:08:27 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall_and_bq(t_game *map)
{
	int	x;
	int	y;

	x = map->x * 64;
	y = map->y * 64;
	if (map->data[map->y][map->x] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall.img, x, y);
	else
		mlx_put_image_to_window(map->mlx, map->win, map->bg.img, x, y);
}

void	draw_player_and_buns(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->length)
		{
			map->y = i;
			map->x = j;
			put_pic(map);
			j++;
		}
		i++;
	}
}

void	draw_player(t_game *map)
{
	int	y;
	int	x;

	x = map->x_p * 64;
	y = map->y_p * 64;
	mlx_put_image_to_window(map->mlx, map->win, map->bg.img, x, y);
	mlx_put_image_to_window(map->mlx, map->win, map->pl.img, x, y);
}

void	check_step(t_game *map, int i, int j)
{
	if (map->data[map->y][map->x] == '1')
		return ;
	if (map->y == map->y_en && map->x == map->x_en)
		game_end(map, 1);
	map->data[i][j] = '0';
	if (map->data[map->y][map->x] == 'C')
		map->buns--;
	else if (map->x == map->xe && map->y == map->ye)
	{
		if (map->buns == 0)
			game_end(map, 0);
		else
		{
			map->xe = map->x;
			map->ye = map->y;
		}
	}
	map->data[map->y][map->x] = 'P';
	map->y_p = map->y;
	map->x_p = map->x;
}

void	move_player(t_game *map, int y, int x)
{
	int	i;
	int	j;

	i = 0;
	map->steps++;
	ft_printf("%d\n", map->steps);
	while (i < map->height)
	{
		j = 0;
		while (j < map->length)
		{
			if (map->data[i][j] == 'P')
			{
				map->x = j + x;
				map->y = i + y;
				check_step(map, i, j);
				check_enemy_step(map);
				return ;
			}
			j++;
		}
		i++;
	}
}
