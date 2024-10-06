/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:44:56 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/25 18:13:50 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rect_chara(t_game *game, int y, int x)
{
	if ((game->plot.map[game->plot.height - 1][x] != '1') || \
		(game->plot.map[0][x] != '1') || (game->plot.map[y] \
		[game->plot.length - 1] != '1') || (game->plot.map[y][0] != '1'))
	{
		endgame("Not surrounded by obstacle!", game, 2);
	}
	if (!(ft_strchr("01CEPHhVv", game->plot.map[y][x])) && BONUS)
		endgame("Invalid character in map", game, 2);
	else if (!(ft_strchr("01CEP", game->plot.map[y][x])) && !BONUS)
		endgame("Invalid character in map", game, 2);
	return ;
}

void	map_check(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->plot.map[y])
	{
		x = 0;
		while (game->plot.map[y][x])
		{
			check_rect_chara(game, y, x);
			x++;
		}
		y++;
	}
}

int	map_len_valid(char **map, t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = ft_strlen(map[0]);
	while (map[i] != 0)
	{
		j = ft_strlen(map[i]);
		if (k != j)
		{
			free_map(game);
			endgame("Not Rectangle Map", game, 2);
		}
		i++;
	}
	return (k);
}
