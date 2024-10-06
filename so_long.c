/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 19:39:00 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/27 20:21:13 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_hook(t_game *game, int event, int mask, int (*f)())
{
	mlx_hook(game->window_pointer, event, mask, f, game);
}

void	init_game(t_game *game, char *path)
{
	init_map(game, path);
	start_pathfinding(game);
	init_so_long(game);
	init_images(game);
	init_bg(game);
	init_hook(game, ON_DESTROY, NO_EVENT_MASK, close_btn);
	init_hook(game, KEY_PRESS, KEY_PRESS_MASK, key_check);
	init_hook(game, KEY_RELEASE, KEY_RELEASE_MASK, release_key);
	mlx_loop_hook(game->mlx_pointer, fix_image, game);
	mlx_loop(game->mlx_pointer);
}

int	is_ber_file(char *argv)
{
	char	*str;

	str = ft_strrchr(argv, '.');
	if (str)
		return (ft_strcmp(str, ".ber") == 0);
	else
		return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc == 2 && (is_ber_file(argv[1])))
		init_game(&game, argv[1]);
	else if (argc == 2 && !(is_ber_file(argv[1])))
		endgame("Can't open file. The format is not supported!", &game, error);
	else if (argc > 2)
		endgame("Can't open multiple files!", &game, error);
	else
		endgame("Please specify file name!", &game, error);
	return (0);
}
