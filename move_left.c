/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:12:25 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/27 18:58:11 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_left(t_game *game)
{
	if ((game->character.x > 32))
	{
		if ((!(game->plot.map[((game->character.y + 31) / 32)]
					[((game->character.x - 1) / 32)] == '1')) && (
				!(game->plot.map[(game->character.y / 32)]
					[((game->character.x - 1) / 32)] == '1')))
		{
			game->character.x -= MOVESPEED;
			print_moves(game);
		}
	}
	return ;
}

void	print_frame_left(t_game *game)
{
	int	i;

	i = game->i.time % (SPEED * 4);
	if (game->moving)
	{
		if (i >= 0 && i < SPEED)
			draw_charfr(game, game->left_a.frame0);
		else if (i >= SPEED && i < (SPEED * 2) * 2)
			draw_charfr(game, game->left_a.frame1);
		else if (i >= SPEED * 2 && i < (SPEED * 3))
			draw_charfr(game, game->left_a.frame2);
		else if (i >= SPEED * 3 && i < (SPEED * 4))
			draw_charfr(game, game->left_a.frame1);
	}
	else if (!game->moving)
		draw_charfr(game, game->character_l.ptr);
}

void	move_left(t_game *game)
{
	game->moving = 1;
	game->character.mem = left;
	draw_bgtile(game, (game->character.x), (game->character.y));
	check_left(game);
	print_player(game);
	return ;
}

/* int	print_frame_left(t_game *game, int old_counter, int new_counter)
{
	if (old_counter == 0)
		draw_charfr(game, game->left_a.frame0);
	if (old_counter == 2)
		draw_charfr(game, game->left_a.frame1);
	if (old_counter == 4)
		draw_charfr(game, game->left_a.frame2);
	return (new_counter);
} */
