/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_ve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:14:23 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/28 11:46:59 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_tile(t_game *game, int y, int x, char z)
{
	draw_bgtile(game, x * 32, y * 32);
	if (z == 'V')
		game->plot.map[y + 1][x] = z;
	else if (z == 'v')
		game->plot.map[y - 1][x] = z;
}

void	print_enemy(t_game *game, int y, int x)
{
	int	i;

	draw_bgtile(game, x * 32, y * 32);
	i = game->i.time % (SPEED * 5);
	if (i >= 0 && i < SPEED)
		draw_obj(game, game->enemy.enemy_a.frame0, x * 32, y * 32);
	else if (i >= SPEED && i < (SPEED * 2))
		draw_obj(game, game->enemy.enemy_a.frame1, x * 32, y * 32);
	else if (i >= (SPEED * 2) && i < (SPEED * 3))
		draw_obj(game, game->enemy.enemy_a.frame2, x * 32, y * 32);
	else if (i >= (SPEED * 3) && i < (SPEED * 4))
		draw_obj(game, game->enemy.enemy_a.frame3, x * 32, y * 32);
	else if (i >= (SPEED * 4) && i <= (SPEED * 5))
		draw_obj(game, game->enemy.enemy_a.frame4, x * 32, y * 32);
	return ;
}

void	check_venemy(t_game *game, int x, int y, char z)
{
	if (player_dist(game, x, y) < 30)
	{
		endgame("\nYOU ARE DEAD. GAME OVER\n ", game, -1);
	}
	else if (z == 'Q')
		print_enemy(game, y, x);
	else
	{
		game->plot.map[y][x] = z;
		print_enemy(game, y, x);
	}
	return ;
}

void	print_ve(t_game *game, int y, int x)
{
	static int	i;

	if (i % 15)
		check_venemy(game, x, y, 'Q');
	else if (game->plot.map[y][x] == 'V' && game->plot.map[y + 1][x] == '0')
	{
		check_venemy(game, x, y, '0');
		move_tile(game, y, x, 'V');
	}
	else if (game->plot.map[y][x] == 'V' && (ft_strchr("1CvVhH",
		game->plot.map[y + 1][x])))
		check_venemy(game, x, y, 'v');
	else if (game->plot.map[y][x] == 'v' && game->plot.map[y - 1][x] == '0')
	{
		check_venemy(game, x, y, '0');
		move_tile(game, y, x, 'v');
	}
	else if (game->plot.map[y][x] == 'v' && (ft_strchr("1CvVhH",
		game->plot.map[y - 1][x])))
	{
		check_venemy(game, x, y, 'V');
	}
	i++;
}
