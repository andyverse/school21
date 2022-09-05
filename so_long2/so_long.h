/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnochiza <fnochiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 04:41:47 by fnochiza          #+#    #+#             */
/*   Updated: 2022/06/25 06:01:43 by fnochiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft/libft.h"

# define BLACK 0x000000

typedef struct s_img
{
	void	*img;
	char	*relative_path;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		steps;
	int		height;
	int		length;
	int		x_p;
	int		zero;
	int		y_p;
	int		xe;
	int		ye;
	int		x_en;
	int		y_en;
	int		go;
	int		x;
	int		y;
	int		buns;
	t_img	wall;
	t_img	bg;
	t_img	pl;
	t_img	col;
	t_img	en;
	t_img	ex;
	t_img	ex2;
	char	**data;
}				t_game;

int		close_game(void);
void	print_error(void);
int		update(t_game *map);
void	free_elem(void *str);
void	put_pic(t_game *map);
void	draw_map(t_game *map);
int		game_over(t_game *map);
void	draw_text(t_game *map);
void	add_enemy(t_game *map);
void	check_name(char **argv);
void	struct_init(t_game **map);
int		game_end(t_game *map, int i);
void	create_textures(t_game *map);
void	check_enemy_step(t_game *map);
void	put_wall_and_bq(t_game *vars);
void	draw_player_and_buns(t_game *map);
void	print_map(int i, int j, t_game *map);
void	check_bun(int i, int j, t_game *map);
void	change_map(t_game *map, int keycode);
void	check_exit(int i, int j, t_game *map);
void	check_wall(int i, int j, t_game *map);
void	move_player(t_game *map, int y, int x);
void	check_player(int i, int j, t_game *map);
void	check_length(int bit, int length, int i);
void	create_array(char **argv, t_game *map, int i);
void	change_player(t_game *map, int keycode, int k);
void	create_map(int argc, char **argv, t_game **map);
void	check_map(int i, int j, t_game *map, char **argv);
void	count_map_size(char **argv, t_game *map, int i, int count);

#endif