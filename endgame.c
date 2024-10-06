/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:35:18 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/28 11:59:49 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game	*game)
{
	int	i;

	i = 0;
	while (game->plot.map[i] != 0)
	{
		free(game->plot.map[i]);
		game->plot.map[i] = NULL;
		i++;
	}
	free(game->plot.map);
}

void	endgame(char *msg, t_game *game, int i)
{
	if (i == -1)
	{
		ft_printf("%s\n", msg);
		destroy_image(game);
		exit(0);
	}
	else if (i == 2)
	{
		ft_printf("Error\n%s\n", msg);
		exit(1);
	}
	else if (i == 3)
	{
		ft_printf("Error\n%s\n", msg);
		free(game->plot.temp);
		exit(1);
	}
	else
	{
		ft_printf("Error\n%s\n", msg);
		destroy_image(game);
		exit(1);
	}
}
