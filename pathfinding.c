/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 18:43:32 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/23 17:36:50 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_playgoal_point(t_game *game, t_point *ppt, t_point *gpt)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (row < game->plot.height)
	{
		while (col < game->plot.length)
		{
			if (game->plot.map[row][col] == 'P')
			{
				ppt->x = col;
				ppt->y = row;
			}
			if (game->plot.map[row][col] == 'E')
			{
				gpt->x = col;
				gpt->y = row;
			}
			col++;
		}
		col = 0;
		row++;
	}
}

void	set_nodevalue(t_map **path_map, t_point pos, t_game *game)
{
	int	row;
	int	col;

	col = pos.x;
	row = pos.y;
	path_map[row][col].c = game->plot.map[row][col];
	path_map[row][col].pos.x = col;
	path_map[row][col].pos.y = row;
	path_map[row][col].flag = 1;
	if (path_map[row][col].c == '1')
		path_map[row][col].open = 0;
	else
		path_map[row][col].open = 1;
}

t_map	**dupe_map(t_game *game)
{
	int		row;
	int		col;
	t_map	**path_map;
	t_point	pos;

	row = 0;
	col = 0;
	path_map = (t_map **)malloc(sizeof(t_map *) * game->plot.height + 1);
	if (!path_map)
		return (NULL);
	while (row < game->plot.height)
	{
		pos.y = row;
		path_map[row] = (t_map *)malloc(sizeof(t_map) * game->plot.length + 1);
		while (col < game->plot.length)
		{
			pos.x = col;
			set_nodevalue(path_map, pos, game);
			col++;
		}
		col = 0;
		row++;
	}
	return (path_map);
}

void	pathfinding(t_game *game, t_point ppt)
{
	t_map	**path_map;
	t_map	*node_list;
	int		collect;
	int		goal;
	int		i;

	i = -1;
	collect = game->i.collectible;
	goal = game->i.exit;
	path_map = dupe_map(game);
	node_list = (t_map *)malloc(sizeof(t_map) * (game->plot.size));
	check_adj(path_map, node_list, path_map[ppt.y][ppt.x]);
	if (node_list[i + 1].flag < 0)
		endgame("Path invalid (player locked)", game, 2);
	while (node_list[++i].flag > 0 && (collect > 0 || goal > 0))
	{
		check_adj(path_map, node_list, node_list[i]);
		if (node_list[i].c == 'C')
			collect--;
		else if (node_list[i].c == 'E')
			goal--;
	}
	free_pmap(path_map, node_list);
	if (collect > 0 || goal > 0)
		endgame("Goal or collectible has no valid path", game, 2);
}

void	start_pathfinding(t_game *game)
{
	t_point	player_pt;
	t_point	goal_pt;

	get_playgoal_point(game, &player_pt, &goal_pt);
	pathfinding(game, player_pt);
}
