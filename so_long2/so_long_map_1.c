/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 18:12:48 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/25 05:04:49 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	free_elem(void *str)
{
	free(str);
	str = NULL;
}

void	check_length(int bit, int length, int i)
{
	if (length != -1 && length != i)
	{
		ft_printf("%d %d %d", bit, length, i);
		print_error();
	}
}

void	count_map_size(char **argv, t_game *map, int i, int count)
{
	int		fd;
	int		bit;
	char	chr;

	fd = open(argv[1], O_RDONLY);
	chr = ' ';
	bit = 1;
	map->length = -1;
	while (chr != '\0' && bit != 0)
	{
		bit = read(fd, &chr, 1);
		if (bit == -1)
			print_error();
		i++;
		if (chr == '\n' || bit == 0)
		{
			check_length(bit, map->length, i);
			map->length = i;
			count++;
			i = 0;
		}
	}
	close(fd);
	map->length -= 1;
	map->height = count;
}

void	create_textures(t_game *map)
{
	int	k;

	k = 64;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->length * k, map->height * k, "GO");
	map->wall.img = mlx_xpm_file_to_image(map->mlx, "./sprite/b.xpm", &k, &k);
	map->ex.img = mlx_xpm_file_to_image(map->mlx, "./sprite/ex.xpm", &k, &k);
	map->ex2.img = mlx_xpm_file_to_image(map->mlx, "./sprite/ex2.xpm", &k, &k);
	map->bg.img = mlx_xpm_file_to_image(map->mlx, "./sprite/g.xpm", &k, &k);
	map->col.img = mlx_xpm_file_to_image(map->mlx, "./sprite/f.xpm", &k, &k);
	map->pl.img = mlx_xpm_file_to_image(map->mlx, "./sprite/t_u.xpm", &k, &k);
	map->pl.img = mlx_xpm_file_to_image(map->mlx, "./sprite/t_u.xpm", &k, &k);
	map->en.img = mlx_xpm_file_to_image(map->mlx, "./sprite/en_r.xpm", &k, &k);
	add_enemy(map);
	draw_map(map);
	draw_player_and_buns(map);
}
