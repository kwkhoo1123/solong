/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkah-wen <kkah-wen@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:21:40 by kkah-wen          #+#    #+#             */
/*   Updated: 2023/06/27 21:11:04 by kkah-wen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_pmap(t_map **pathmap, t_map *node_list)
{
	int	i;

	i = 0;
	free(pathmap);
	free(node_list);
}

int	find_tile(t_map *nd_list, t_map nd)
{
	int	i;

	i = 0;
	while (nd_list[i].flag == 1)
	{
		if (nd_list[i].pos.x == nd.pos.x && nd_list[i].pos.y == nd.pos.y)
			return (1);
		i++;
	}
	return (0);
}

void	add_tile(t_map *node_list, t_map node)
{
	int	i;

	i = 0;
	while (node_list[i].flag == 1)
		i++;
	if (node.open && !find_tile(node_list, node))
		node_list[i] = node;
}

int	check_tile(t_map **path_map, t_map node)
{
	if (path_map[node.pos.y][node.pos.x].open)
		return (1);
	else
		return (0);
}

void	check_adj(t_map **path_map, t_map *node_list, t_map node)
{
	int	x;
	int	y;

	x = node.pos.x;
	y = node.pos.y;
	if (!path_map)
		return ;
	if (path_map[y][x].open)
	{
		path_map[y][x].open = 0;
		if (check_tile(path_map, path_map[y + 1][x]))
			add_tile(node_list, path_map[y + 1][x]);
		if (check_tile(path_map, path_map[y][x + 1]))
			add_tile(node_list, path_map[y][x + 1]);
		if (check_tile(path_map, path_map[y - 1][x]))
			add_tile(node_list, path_map[y - 1][x]);
		if (check_tile(path_map, path_map[y][x - 1]))
			add_tile(node_list, path_map[y][x - 1]);
	}
}
