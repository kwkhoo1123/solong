/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:33:07 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/26 17:36:13 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	new_sprite(void *mlx, char *path)
{
	t_img	img;

	img.x = 0;
	img.y = 0;
	img.mem = 0;
	img.ptr = mlx_xpm_file_to_image(mlx, path, &img.x, &img.y);
	return (img);
}

void	init_sprites(t_game	*game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	init_collect(game, i, j);
	init_player_down(game, i, j);
	init_player_left(game, i, j);
	init_player_right(game, i, j);
	init_player_up(game, i, j);
	init_enemies(game, i, j);
}

void	init_images(t_game *game)
{
	init_sprites(game);
	game->wall = new_sprite(game->mlx_pointer,
			"./img/tree.xpm");
	game->floor = new_sprite(game->mlx_pointer,
			"./img/grass.xpm");
	game->collect = new_sprite(game->mlx_pointer,
			"./img/treasure_0.xpm");
	game->goal = new_sprite(game->mlx_pointer,
			"./img/goal.xpm");
	game->character = new_sprite(game->mlx_pointer,
			"./img/player_walk/player_d_1.xpm");
	game->character_l = new_sprite(game->mlx_pointer,
			"./img/player_walk/player_l_1.xpm");
	game->character_r = new_sprite(game->mlx_pointer,
			"./img/player_walk/player_r_1.xpm");
	game->character_u = new_sprite(game->mlx_pointer,
			"./img/player_walk/player_u_1.xpm");
}
