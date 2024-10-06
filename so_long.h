/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 20:49:30 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/28 11:51:28 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"

# include "libft/libft.h"
# include "sl_utils.h"

# include <fcntl.h> 
# include <unistd.h> 
# include <stdlib.h> 
# include <stdio.h> 
# include <stdbool.h> 
# include <time.h>
# include <math.h>

# ifndef BONUS
#  define BONUS 0
# endif

void	free_map(t_game	*game);
void	endgame(char *msg, t_game *game, int i);

void	map_check(t_game *game);

void	check_adj(t_map **path_map, t_map *node_list, t_map node);
void	free_pmap(t_map **pathmap, t_map *node_list);

void	start_pathfinding(t_game *game);

void	init_map(t_game *game, char *path);
int		map_len_valid(char **map, t_game *game);
void	init_bg(t_game *game);
void	player_init(t_game	*game);
void	map_extra_row(t_game *game);
void	map_fill(t_game *game, int y, int x);
void	redraw_surrounding(t_game *game);

void	draw_obj(t_game *game, void *img_ptr, int x, int y);
void	draw_bgtile(t_game *game, int x, int y);

void	print_collect(t_game *game, int y, int x);
void	print_map_string(t_game *game);
int		fix_image(t_game *game);

void	init_so_long(t_game *game);
int		render_units(t_game *game);
int		close_btn(t_game *game);
int		on_expose(int visible, t_game *game);
int		on_unexpose(t_game *game);

void	init_images(t_game *game);

void	init_collect(t_game *game, int i, int j);
void	init_player_down(t_game *game, int i, int j);
void	init_player_right(t_game *game, int i, int j);
void	init_player_left(t_game *game, int i, int j);
void	init_player_up(t_game *game, int i, int j);

int		key_check(int keycode, t_game *game);
void	print_moves(t_game *game);
void	move_right(t_game *parameter);
void	move_left(t_game *parameter);
void	move_up(t_game *parameter);
void	move_down(t_game *parameter);
void	draw_charfr(t_game *game, void *frame);
void	print_player(t_game *game);
void	print_frame_up(t_game *game);
void	print_frame_down(t_game *game);
void	print_frame_left(t_game *game);
void	print_frame_right(t_game *game);

void	init_enemies(t_game *game, int i, int j);
void	destroy_enemies(t_game *game);

int		player_dist(t_game *game, int x, int y);
void	print_ve(t_game *game, int y, int x);
void	print_he(t_game *game, int y, int x);

void	destroy_image(t_game *game);

void	delay(int milliseconds);
void	render_anim(t_game *game);
int		release_key(int keycode, t_game *game);

#endif