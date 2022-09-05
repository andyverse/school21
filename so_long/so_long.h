/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 04:41:47 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/20 06:12:13 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/libft.h"

typedef struct s_game_map
{
	int		height;
	int		length;
	int		player_pos_x;
	int		player_pos_y;
	int		game_score;
	int		max_score;
	int		game_over;
	int		steps;
	int		drawp;
	int		enemyset;
	char	*data;
	void	*wall;
	void	*exit;
	void	*player;
	void	*bg;
	void	*star;
	void	*enemy;
	void	*marvin;
	int		*enemypos;
	char	*err_msg;
}	t_game_map;

typedef struct s_render_v {
	void	*mlx;
	void	*win;
}	t_render_v;

void	print_error(void);
void	free_elem(void *str);
void	check_name(char **argv);
void	struct_init(t_game_map **map);
void	free_struct(t_game_map **map);
void	check_length(int bit, int length, int i);
void	create_map(int argc, char **argv, t_game_map **map);
void	print_map(int i, int j, t_game_map **map, char ***map_array);
void	check_map(int i, int j, t_game_map **map, char **map_array);
void	check_bun(int i, int j, t_game_map **map, char **map_array);
void	check_exit(int i, int j, t_game_map **map, char **map_array);
void	check_wall(int i, int j, t_game_map **map, char **map_array);
void	check_player(int i, int j, t_game_map **map, char **map_array);
void	count_map_size(char **argv, t_game_map **map, int i, int count);
void	create_array(char **argv, t_game_map **map, char ***array, int i);

#endif