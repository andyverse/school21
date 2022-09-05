/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 01:11:54 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/23 05:10:34 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game_map	*map;
	t_render_v	*mlxx;

	map = malloc(sizeof(t_game_map));
	struct_init(&map);
	create_map(argc, argv, &map);
	write(1, "\n", 1);
	mlxx = malloc(sizeof(t_render_v));
	mlxx->mlx = mlx_init();
	mlxx->win = mlx_new_window(mlxx->mlx, 33 * 10, 11 * 10, "so_long");
	mlx_loop(mlxx->mlx);
}
