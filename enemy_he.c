/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_he.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:29:48 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/28 11:47:07 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_htile(t_game *game, int y, int x, char z)
{
	draw_bgtile(game, x * 32, y * 32);
	if (z == 'H')
		game->plot.map[y][x + 1] = z;
	else if (z == 'h')
		game->plot.map[y][x - 1] = z;
}

void	print_henemy(t_game *game, int y, int x)
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

void	check_henemy(t_game *game, int x, int y, char z)
{
	if (player_dist(game, x, y) < 30)
	{
		endgame("\nYOU ARE DEAD. GAME OVER\n ", game, -1);
	}
	else if (z == 'Q')
		print_henemy(game, y, x);
	else
	{
		game->plot.map[y][x] = z;
		print_henemy(game, y, x);
	}
	return ;
}

void	print_he(t_game *game, int y, int x)
{
	static int	i;

	if (i % 15)
		check_henemy(game, x, y, 'Q');
	else if (game->plot.map[y][x] == 'H' && game->plot.map[y][x + 1] == '0')
	{
		check_henemy(game, x, y, '0');
		move_htile(game, y, x, 'H');
	}
	else if (game->plot.map[y][x] == 'H' && (ft_strchr("1CvVhH",
		game->plot.map[y][x + 1])))
		check_henemy(game, x, y, 'h');
	else if (game->plot.map[y][x] == 'h' && game->plot.map[y][x - 1] == '0')
	{
		check_henemy(game, x, y, '0');
		move_htile(game, y, x, 'h');
	}
	else if (game->plot.map[y][x] == 'h' && (ft_strchr("1CvVhH",
		game->plot.map[y][x - 1])))
	{
		check_henemy(game, x, y, 'H');
	}
	i++;
}
