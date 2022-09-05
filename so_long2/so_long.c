/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 01:11:54 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/25 06:01:56 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pic(t_game *map)
{
	int	x;
	int	y;
	int	xe;
	int	ye;

	x = map->x * 64;
	y = map->y * 64;
	xe = map->xe * 64;
	ye = map->ye * 64;
	xe = map->x_en * 64;
	ye = map->y_en * 64;
	if (map->x_en != -1)
		mlx_put_image_to_window(map->mlx, map->win, map->en.img, xe, ye);
	if (map->data[map->y][map->x] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall.img, x, y);
	if (map->data[map->y][map->x] == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->bg.img, x, y);
	if (map->data[map->y][map->x] == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->col.img, x, y);
	if (map->data[map->y][map->x] == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->pl.img, x, y);
		map->x_p = map->x;
		map->y_p = map->y;
	}
}

int	keys(int keycode, t_game *map)
{
	int	k;

	k = 64;
	if (keycode == 53)
		close_game();
	if ((keycode == 1 || keycode == 13 || keycode == 2 || keycode == 0))
	{
		change_player(map, keycode, k);
		draw_player_and_buns(map);
		draw_text(map);
	}
	return (0);
}

int	game_end(t_game *map, int i)
{
	if (i == 1)
		ft_printf("GAME OVER\n");
	else if (map->buns == 0)
		ft_printf("GAME WON!\n");
	else
		ft_printf("GAME END\n");
	exit(0);
}

void	draw_map(t_game *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->length)
		{
			map->x = j;
			map->y = i;
			put_wall_and_bq(map);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int			n;
	int			i;
	int			j;
	int			fd;
	t_game		*map;

	i = 0;
	j = 0;
	n = 64;
	if (argc < 2)
		return (0);
	map = (t_game *) malloc(sizeof(t_game));
	fd = open(argv[1], O_RDONLY);
	count_map_size(argv, map, 0, 0);
	create_array(argv, map, 0);
	check_map(0, 0, map, argv);
	create_textures(map);
	map->steps = 0;
	mlx_hook(map->win, 2, 1L << 0, keys, map);
	mlx_hook(map->win, 17, 1L << 0, close_game, map);
	mlx_loop_hook(map->mlx, update, map);
	mlx_do_sync(map->mlx);
	mlx_loop(map->mlx);
}
