/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:47:18 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/27 20:43:37 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_init(t_game	*game)
{
	int	y;
	int	x;

	y = 0;
	while (game->plot.map[y])
	{
		x = 0;
		while (game->plot.map[y][x])
		{
			if (game->plot.map[y][x] == 'P')
			{
				game->character.x = (32 * x);
				game->character.y = (32 * y);
				draw_obj(game, game->character.ptr, (32 * x), (32 * y));
				game->plot.map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
	game->moving = 0;
}

void	print_collect(t_game *game, int y, int x)
{
	int	i;

	i = game->i.time % (SPEED * 2);
	if (i >= 0 && i < SPEED)
		draw_obj(game, game->collect_a.frame0, x * 32, y * 32);
	if (i >= SPEED && i < (SPEED * 2))
		draw_obj(game, game->collect_a.frame1, x * 32, y * 32);
	if (i >= (SPEED * 2))
		i = 0;
	if (player_dist(game, x, y) < 32)
	{
		game->plot.map[y][x] = '0';
		game->i.collectible--;
		ft_printf("Remaining treasures: %d\n", game->i.collectible);
		draw_bgtile(game, x * 32, y * 32);
	}
}

int	fix_image(t_game *game)
{
	delay(60);
	render_anim(game);
	game->i.time++;
	return (0);
}
