/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:43:56 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/26 16:46:58 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_mains(t_game *game)
{
	mlx_destroy_image(game->mlx_pointer, game->collect_a.frame0);
	mlx_destroy_image(game->mlx_pointer, game->collect_a.frame1);
	mlx_destroy_image(game->mlx_pointer, game->wall.ptr);
	mlx_destroy_image(game->mlx_pointer, game->floor.ptr);
	mlx_destroy_image(game->mlx_pointer, game->collect.ptr);
	mlx_destroy_image(game->mlx_pointer, game->goal.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character_l.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character_r.ptr);
	mlx_destroy_image(game->mlx_pointer, game->character_u.ptr);
}

void	destroy_player_frames(t_game *game)
{
	mlx_destroy_image(game->mlx_pointer, game->down_a.frame0);
	mlx_destroy_image(game->mlx_pointer, game->down_a.frame1);
	mlx_destroy_image(game->mlx_pointer, game->down_a.frame2);
	mlx_destroy_image(game->mlx_pointer, game->right_a.frame0);
	mlx_destroy_image(game->mlx_pointer, game->right_a.frame1);
	mlx_destroy_image(game->mlx_pointer, game->right_a.frame2);
	mlx_destroy_image(game->mlx_pointer, game->left_a.frame0);
	mlx_destroy_image(game->mlx_pointer, game->left_a.frame1);
	mlx_destroy_image(game->mlx_pointer, game->left_a.frame2);
	mlx_destroy_image(game->mlx_pointer, game->up_a.frame0);
	mlx_destroy_image(game->mlx_pointer, game->up_a.frame1);
	mlx_destroy_image(game->mlx_pointer, game->up_a.frame2);
}

void	destroy_image(t_game *game)
{
	destroy_enemies(game);
	destroy_mains(game);
	destroy_player_frames(game);
	mlx_destroy_window(game->mlx_pointer, game->window_pointer);
	free_map(game);
	free(game->mlx_pointer);
}
