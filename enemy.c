/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 16:54:44 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/28 11:54:26 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_enemies(t_game *game, int i, int j)
{
	game->enemy.enemy_a.frame0 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/wisp/fire0.xpm", &i, &j);
	game->enemy.enemy_a.frame1 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/wisp/fire1.xpm", &i, &j);
	game->enemy.enemy_a.frame2 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/wisp/fire2.xpm", &i, &j);
	game->enemy.enemy_a.frame3 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/wisp/fire3.xpm", &i, &j);
	game->enemy.enemy_a.frame4 = mlx_xpm_file_to_image(game->mlx_pointer,
			"./img/wisp/fire4.xpm", &i, &j);
}

void	destroy_enemies(t_game *game)
{
	mlx_destroy_image(game->mlx_pointer, game->enemy.enemy_a.frame0);
	mlx_destroy_image(game->mlx_pointer, game->enemy.enemy_a.frame1);
	mlx_destroy_image(game->mlx_pointer, game->enemy.enemy_a.frame2);
	mlx_destroy_image(game->mlx_pointer, game->enemy.enemy_a.frame3);
	mlx_destroy_image(game->mlx_pointer, game->enemy.enemy_a.frame4);
}

int	player_dist(t_game *game, int x, int y)
{
	int	dist;
	int	x_d;
	int	y_d;

	x_d = x * 32 - game->character.x;
	y_d = y * 32 - game->character.y;
	dist = sqrt((x_d * x_d) + (y_d * y_d));
	return (dist);
}
