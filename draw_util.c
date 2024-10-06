/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:33:36 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/28 11:53:20 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_bgtile(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		game->floor.ptr, x, y);
}

void	draw_obj(t_game *game, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx_pointer, game->window_pointer,
		img_ptr, x, y);
}

void	redraw_tile(t_game *game, int y, int x)
{
	if (x >= 1 && y >= 1 && x < game->plot.length - 1
		&& y < game->plot.height - 1)
	{
		if (game->plot.map[y][x] == 'E')
		{
			map_fill(game, y, x);
			if (game->i.collectible == 0 && player_dist(game, x, y) < 32)
				endgame("\nYOU WIN\n", game, -1);
		}
	}
}

void	redraw_surrounding(t_game *game)
{
	int	y;
	int	x;

	y = game->character.y / 32;
	x = game->character.x / 32;
	redraw_tile(game, y, x);
	redraw_tile(game, y - 1, x);
	redraw_tile(game, y - 1, x - 1);
	redraw_tile(game, y - 1, x + 1);
	redraw_tile(game, y - 2, x);
	redraw_tile(game, y + 1, x);
	redraw_tile(game, y + 1, x - 1);
	redraw_tile(game, y + 1, x + 1);
	redraw_tile(game, y + 2, x);
	redraw_tile(game, y, x - 1);
	redraw_tile(game, y, x - 2);
	redraw_tile(game, y, x + 1);
	redraw_tile(game, y, x + 2);
}

void	print_map_string(t_game *game)
{
	char	*string;

	if (BONUS)
	{
		string = ft_itoa(game->i.movements);
		map_extra_row(game);
		if (game->plot.length < 9)
		{
			mlx_string_put(game->mlx_pointer, game->window_pointer, 4,
				((game->plot.height) * 32) - 0, 0xFFFFFF, "Movements: ");
			mlx_string_put(game->mlx_pointer, game->window_pointer, 104,
				((game->plot.height) * 32) - 0, 0xFFFFFF, string);
		}
		else
		{
			mlx_string_put(game->mlx_pointer, game->window_pointer,
				(((game->plot.length - 4) / 2) * 32),
				(game->plot.height * 32) - 0, 0xFFFFFF, "Movements: ");
			mlx_string_put(game->mlx_pointer, game->window_pointer,
				(((game->plot.length - 4) / 2) * 32) + 100,
				(game->plot.height * 32) - 0, 0xFFFFFF, string);
		}
		free(string);
		string = NULL;
	}
}
