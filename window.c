/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:43:41 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/28 11:55:56 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render_units(t_game *game)
{
	render_anim(game);
	return (0);
}

int	close_btn(t_game *game)
{
	endgame("exit with close btn", game, -1);
	return (0);
}

void	init_so_long(t_game *game)
{
	game->mlx_pointer = mlx_init();
	game->window_pointer = mlx_new_window(game->mlx_pointer,
			(game->plot.length * 32), ((game->plot.height * 32) + 32 * BONUS),
			WINDOW_NAME);
}

/* 
int	render_units(t_game *game)
{
	render_anim(game);
	if (game->character.mem == down)
		draw_obj(game, game->character.ptr,
			game->character.x, game->character.y);
	else if (game->character.mem == left)
		draw_obj(game, game->character_l.ptr,
			game->character.x, game->character.y);
	else if (game->character.mem == right)
		draw_obj(game, game->character_r.ptr,
			game->character.x, game->character.y);
	else if (game->character.mem == up)
		draw_obj(game, game->character_u.ptr,
			game->character.x, game->character.y);
	return (0);
} */