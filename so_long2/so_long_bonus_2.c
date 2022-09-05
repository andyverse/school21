/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 04:41:50 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/25 06:01:30 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	animation(t_game *map)
{
	int			x;
	int			y;
	static int	a;

	x = map->xe * 64;
	y = map->ye * 64;
	if (a < 20)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->bg.img, x, y);
		mlx_put_image_to_window(map->mlx, map->win, map->ex.img, x, y);
	}
	else if (a > 20)
	{
		mlx_put_image_to_window(map->mlx, map->win, map->bg.img, x, y);
		mlx_put_image_to_window(map->mlx, map->win, map->ex2.img, x, y);
	}
	a++;
	if (a > 40)
	a = 0;
}

int	update(t_game *map)
{
	animation(map);
	return (1);
}

int	close_game(void)
{
	ft_printf("Game closed\n");
	exit(0);
	return (1);
}
