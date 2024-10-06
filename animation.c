/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 16:46:34 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/28 11:51:35 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_anim(t_game *game, int y, int x)
{
	if (game->plot.map[y][x] == 'C')
		print_collect(game, y, x);
	else if (ft_strchr("Vv", game->plot.map[y][x]))
		print_ve(game, y, x);
	else if (ft_strchr("Hh", game->plot.map[y][x]))
		print_he(game, y, x);
}

int	release_key(int keycode, t_game *game)
{
	int	i;

	i = keycode;
	game->moving = 0;
	return (0);
}

void	delay(int milliseconds)
{
	clock_t	pause;
	clock_t	now;
	clock_t	then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	then = clock();
	now = clock();
	while ((now - then) < pause)
	{
		now = clock();
	}
	return ;
}

void	render_anim(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->plot.map[y])
	{
		x = 0;
		while (game->plot.map[y][x])
		{
			print_anim(game, y, x);
			x++;
		}
		y++;
	}
}
/* 
void	delay(int milliseconds)
{
	clock_t	pause;
	clock_t	now;
	clock_t	then;

	pause = milliseconds * (CLOCKS_PER_SEC / 1000);
	then = clock();
	now = clock();
	printf("now-then: %zu pause: %zu\n", now-then, pause);
	while ((now - then) < pause)
	{
		now = clock();
		printf("delaying: %zu pause: %zu\n", now-then, pause);
	}
	return ;
}
 */