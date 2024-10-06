/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:00:47 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/27 19:02:15 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_check(int keycode, t_game *game)
{
	game->character.mem = 0;
	if (keycode == KEY_ESC)
		endgame("exit with esc key", game, -1);
	if (keycode == KEY_LEFT)
		move_left(game);
	else if (keycode == KEY_RIGHT)
		move_right(game);
	else if (keycode == KEY_UP)
		move_up(game);
	else if (keycode == KEY_DOWN)
		move_down(game);
	return (0);
}

void	draw_charfr(t_game *game, void *frame)
{
	draw_obj(game, frame, game->character.x, game->character.y);
}

void	print_player(t_game *game)
{
	redraw_surrounding(game);
	if (game->character.mem == down)
		print_frame_down(game);
	else if (game->character.mem == left)
		print_frame_left(game);
	else if (game->character.mem == right)
		print_frame_right(game);
	else if (game->character.mem == up)
		print_frame_up(game);
}

void	print_moves(t_game *game)
{
	game->i.movements += 1;
	if (BONUS)
		print_map_string(game);
	else if (!BONUS)
		ft_printf("Movement: %d\n", game->i.movements);
}

/* int	check_win(t_game *game)
{
	if ((game->plot.map[game->character.y / 32][game->character.x / 32] == 'E')
		&& game->i.collectible == 0 && (game->plot.map[game->character.y / 32]
		[((game->character.x + 30) / 32)] == 'E' ))
		return (1);
	else if (((game->plot.map[(game->character.y + 16) / 32]
				[game->character.x / 32] == 'E') && game->i.collectible == 0
			&& (game->plot.map[(game->character.y + 16) / 32]
				[((game->character.x + 30) / 32)] == 'E' )))
		return (1);
	return (0);
} */
