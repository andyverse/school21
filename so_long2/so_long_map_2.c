/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:18:28 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/25 05:58:10 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_array(char **argv, t_game *map, int i)
{
	int		fd;

	map->data = (char **) malloc(map->length * sizeof(char *));
	fd = open(argv[1], O_RDONLY);
	map->data[i] = get_next_line(fd);
	while (map->data[i] != NULL)
	{
		i++;
		map->data[i] = get_next_line(fd);
	}
	map->data[i] = NULL;
	map->x_en = 0;
	map->y_en = 0;
	close(fd);
}

void	print_map(int i, int j, t_game *map)
{
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->length + 1)
		{
			ft_printf("%c", map->data[i][j]);
			j++;
		}
		i++;
	}
}

void	check_wall(int i, int j, t_game *map)
{
	while (i < map->height)
	{
		j = 0;
		while (j < map->length)
		{
			if (i == 0 || i == map->height - 1)
			{
				if (ft_strchr("1\n", map->data[i][j]) == NULL)
					print_error();
			}
			if (j == 0 || j == map->length - 1)
			{
				if (map->data[i][j] != '1')
					print_error();
			}
			j++;
		}
		i++;
	}
}

void	check_player(int i, int j, t_game *map)
{
	int	flag;

	flag = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->length)
		{
			if (map->data[i][j] == 'P')
				flag++;
			j++;
		}
		i++;
	}
	if (flag == 0)
		print_error();
}

void	check_name(char **argv)
{
	int		i;
	char	*name;

	i = 0;
	name = ft_strchr(argv[1], '.');
	while (i < ft_strlen(name))
	{
		if (ft_strchr(".ber", name[i]) == NULL)
			print_error();
		i++;
	}
}
