/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:44:58 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/27 19:07:50 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_extra_row(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->plot.length)
	{
		draw_bgtile(game, (32 * x), (32 * game->plot.height));
		x++;
	}
}

void	map_fill(t_game *game, int y, int x)
{
	draw_bgtile(game, (32 * x), (32 * y));
	if (game->plot.map[y][x] == 'E')
	{
		game->goal.x = x * 32;
		game->goal.y = y * 32;
		draw_obj(game, game->goal.ptr, (32 * x), (32 * y));
	}
	else if (game->plot.map[y][x] == '1')
		draw_obj(game, game->wall.ptr, (32 * x), (32 * y));
}

void	init_bg(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->plot.map[y])
	{
		x = 0;
		while (game->plot.map[y][x])
		{
			map_fill(game, y, x);
			x++;
		}
		y++;
	}
	print_map_string(game);
	player_init(game);
}

static t_counter	start_counter(char *string_map, t_game *game, int i)
{
	t_counter	cnt;

	cnt.collectible = 0;
	cnt.start = 0;
	cnt.exit = 0;
	cnt.movements = 0;
	cnt.empty = 0;
	while (string_map[i] != '\0')
	{
		if ((string_map[i] == '\n') && (ft_strchr("\n\0", string_map[i + 1])))
			endgame("Invalid file!", game, 3);
		if (string_map[i] == 'C')
			cnt.collectible++;
		else if (string_map[i] == 'E')
			cnt.exit++;
		else if (string_map[i] == 'P')
			cnt.start++;
		else if (string_map[i] == '0')
			cnt.empty++;
		i++;
	}
	if (cnt.start != 1 || cnt.exit != 1 || cnt.collectible < 1)
		endgame("Invalid map character count", game, 3);
	return (cnt);
}

void	init_map(t_game *game, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		endgame("Can't find or open file!", game, 2);
	game->plot.temp = ft_strdup("");
	game->plot.height = 0;
	while (fd)
	{
		game->plot.line = get_next_line(fd);
		if (game->plot.line == NULL)
			break ;
		game->plot.temp = ft_strjoin(game->plot.temp, game->plot.line);
		free(game->plot.line);
		game->plot.height++;
	}
	game->i = start_counter(game->plot.temp, game, 0);
	game->plot.map = ft_split(game->plot.temp, '\n');
	free(game->plot.temp);
	game->plot.length = map_len_valid(game->plot.map, game);
	game->plot.size = game->plot.length * game->plot.height;
	map_check(game);
	close(fd);
}
