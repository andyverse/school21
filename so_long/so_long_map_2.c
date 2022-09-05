/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:18:28 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/23 05:13:42 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_array(char **argv, t_game_map **map, char ***array, int i)
{
	int		fd;
	int		j;
	char	*str;

	(*array) = (char **) malloc(3 * sizeof(char));
	fd = open(argv[1], O_RDONLY);
	//ft_printf("%d %d\n", map->length, (*map)->height);
	while (i < 3 && str != NULL)
	{
		str = get_next_line(fd);
		//ft_printf("%s", str);
		if (str == NULL)
			break ;
		if (str != NULL)
		{
			j = 0;
			(*array)[i] = malloc(((*map)->length + 1) * sizeof(char));
			while (j < (*map)->length) // если тут указываю (*map)->length, то он ломается
			{
				(*array)[i][j] = str[j];
				j++;
			}
			(*array)[i][j] = '\0';
		}
		i++;
		free(str);
	}
	close(fd);
}

void	print_map(int i, int j, t_game_map **map, char ***map_array)
{
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 11)
		{
			ft_printf("%c", (*map_array)[i][j]);
			j++;
		}
		i++;
	}
}

void	check_wall(int i, int j, t_game_map **map, char **map_array)
{
	while (i < (*map)->height)
	{
		j = 0;
		while (j < (*map)->length)
		{
			if (i == 0 || i == (*map)->height - 1)
			{
				if (ft_strchr("1\n", map_array[i][j]) == NULL)
				{
					ft_printf("\nWALLERR\n%d:%d - %c\n", i, j, map_array[i][j]);
					print_error();
				}
			}
			if (j == 0 || j == (*map)->length - 2)
			{
				if (map_array[i][j] != '1')
				{
					ft_printf("\nWALLERR\n%d:%d - %c\n", i, j, map_array[i][j]);
					print_error();
				}
			}
			j++;
		}
		i++;
	}
}

void	check_player(int i, int j, t_game_map **map, char **map_array)
{
	int	flag;

	flag = 0;
	i = 0;
	while (i < (*map)->height)
	{
		j = 0;
		while (j < (*map)->length)
		{
			if (map_array[i][j] == 'P')
				flag++;
			j++;
		}
		i++;
	}
	if (flag == 0)
	{
		ft_printf("Player Error");
		print_error();
	}
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
		{
			ft_printf("Name Error");
			print_error();
		}
		i++;
	}
}
