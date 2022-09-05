/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:09:09 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/25 06:01:03 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enemy_if(t_game *map, int flag, int i, int j)
{
	int	ret;

	map->go = 1;
	ret = flag;
	if (map->data[i][j] == '0' && flag == 0)
	{
		map->x_en = j;
		map->y_en = i;
	}
	if (map->data[i][j - 1] == '0' && map->data[i][j] == '0' && \
		map->data[i][j + 1] == '0')
	{
		map->x_en = j;
		map->y_en = i;
		flag = 1;
	}
	ret = flag;
	return (ret);
}

void	delete_enemy(t_game *map)
{
	map->x_en = -1;
	map->y_en = -1;
}

void	add_enemy(t_game *map)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	flag = 0;
	while (i < map->height - 1)
	{
		j = 1;
		while (j < map->length - 1)
		{
			if (enemy_if(map, flag, i, j) == 1)
				return ;
			j++;
		}
		i++;
	}
	if (flag == 0)
		delete_enemy(map);
}

void	draw_text(t_game *map)
{
	char	*str;

	str = ft_itoa(map->steps);
	mlx_string_put(map->mlx, map->win, 64 * map->length - 126, 28, BLACK, str);
	free(str);
}

void	check_enemy_step(t_game *map)
{
	int		k;
	char	*enem;

	k = 64;
	enem = "./sprite/en_r.xpm";
	if (map->x_en == -1)
		return ;
	if (map->y_p == map->y_en && map->x_p == map->x_en + map->go)
		game_end(map, 1);
	if (map->go == 1 && map->data[map->y_en][map->x_en + map->go] != '0')
		map->go = -1;
	else if (map->go == -1 && map->data[map->y_en][map->x_en + map->go] != '0')
		map->go = 1;
	if (map->data[map->y_en][map->x_en + map->go] == '0' && map->go == 1)
	{
		map->x_en = map->x_en + map->go;
		enem = "./sprite/en_r.xpm";
	}
	else if (map->data[map->y_en][map->x_en + map->go] == '0' && map->go == -1)
	{
		map->x_en = map->x_en + map->go;
		enem = "./sprite/en_l.xpm";
	}
	map->en.img = mlx_xpm_file_to_image(map->mlx, enem, &k, &k);
}
