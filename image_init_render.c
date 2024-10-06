/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:13:08 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/26 16:46:17 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_collect(t_game *game, int i, int j)
{
	game->collect_a.frame0 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/treasure_0.xpm", &i, &j);
	game->collect_a.frame1 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/treasure_1.xpm", &i, &j);
}

void	init_player_down(t_game *game, int i, int j)
{
	game->down_a.frame0 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/player_walk/player_d_0.xpm", &i, &j);
	game->down_a.frame1 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/player_walk/player_d_1.xpm", &i, &j);
	game->down_a.frame2 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/player_walk/player_d_2.xpm", &i, &j);
}

void	init_player_right(t_game *game, int i, int j)
{
	game->right_a.frame0 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/player_walk/player_r_0.xpm", &i, &j);
	game->right_a.frame1 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/player_walk/player_r_1.xpm", &i, &j);
	game->right_a.frame2 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/player_walk/player_r_2.xpm", &i, &j);
}

void	init_player_left(t_game *game, int i, int j)
{
	game->left_a.frame0 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/player_walk/player_l_0.xpm", &i, &j);
	game->left_a.frame1 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/player_walk/player_l_1.xpm", &i, &j);
	game->left_a.frame2 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/player_walk/player_l_2.xpm", &i, &j);
}

void	init_player_up(t_game *game, int i, int j)
{
	game->up_a.frame0 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/player_walk/player_u_0.xpm", &i, &j);
	game->up_a.frame1 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/player_walk/player_u_1.xpm", &i, &j);
	game->up_a.frame2 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/player_walk/player_u_2.xpm", &i, &j);
}
