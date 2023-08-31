/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:37:43 by sawang            #+#    #+#             */
/*   Updated: 2023/08/31 19:16:01 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "raycast.h"
#include "hook.h"

#include <stdio.h>

t_vec	get_player_pos(int i, int j)
{
	t_vec	pos;

	pos.x = i;
	pos.y = j;
	return (pos);
}

double	get_player_dir(int i, int j, char **map)
{
	double	dir;

	dir = 0;
	if (map[j][i] == 'N')
		dir = 90 * PI / 180;
	else if (map[j][i] == 'S')
		dir = 3 * PI / 2;
	else if (map[j][i] == 'E')
		dir = 0;
	else if (map[j][i] == 'W')
		dir = PI;
	return (dir);
}

void	get_initial_player_info(t_map_data s_map_data, \
	int tile_size, t_player *player)
{
	int			i;
	int			j;

	j = 0;
	while (j < s_map_data.height)
	{
		i = 0;
		while (i < s_map_data.width)
		{
			if (s_map_data.map[j][i] == 'N' || s_map_data.map[j][i] == 'S' || \
				s_map_data.map[j][i] == 'E' || s_map_data.map[j][i] == 'W')
			{
				player->pos = get_player_pos(i, j);
				player->dir = get_player_dir(i, j, s_map_data.map);
				player->pos_modif.x = (player->pos.x + 0.5) * tile_size;
				player->pos_modif.y = (player->pos.y + 0.5) * tile_size;
				player->dir_modif = player->dir;
			}
			i++;
		}
		j++;
	}
}

void	init_map_size(t_map_size *s_map_size)
{
	s_map_size->height = HEIGHT;
	s_map_size->width = WIDTH;
	s_map_size->tile_size = TILE_SIZE;
}

void	init_input(t_input *input)
{
	input->angle = 0;
	input->hori_delta = 0;
	input->vert_delta = 0;
}

// void	init_minimap_size(t_map_size *minimap_size)
// {
// 	minimap_size->height = HEIGHT;
// 	minimap_size->tile_size = HEIGHT / mapHeight;
// 	minimap_size->width = minimap_size->tile_size * mapWidth;
// 	printf("minimap_height = %d\n", minimap_size->height);
// 	printf("minimap_width = %d\n", minimap_size->width);
// 	printf("minimap_tile_size = %d\n", minimap_size->tile_size);
// }
