/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:32:22 by sawang            #+#    #+#             */
/*   Updated: 2023/08/22 21:32:22 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycast.h"

#include <stdio.h>

void	cast_ray(t_ray *rays, int worldMap[mapHeight][mapWidth], t_player player, \
	t_map_size map_size)
{
	int		i;
	double	ray_dir;

	i = 0;
	ray_dir = player.dir_modif + 30 * PI / 180;
	if (ray_dir > 2 * PI)
		ray_dir -= 2 * PI;
	// do I need check the angle after rotate? or just check the angle before rotate?
	// if (ray_dir < 0)
		// ray_dir += 2 * PI;
	//calculate clockwise ray
	while (i < map_size.width)
	{
		rays[i].ray_dir = ray_dir;
		printf("ray_dir = %f\t", rays[i].ray_dir);
		// printf("ray_dir in degree = %f\n", ray_dir * 180 / PI);
		determine_intersec(&rays[i], worldMap, map_size.tile_size, player);
		printf("the hit point at the map is [%d][%d]\n", \
			(int)(rays[i].intersec.y / map_size.tile_size), (int)(rays[i].intersec.x / map_size.tile_size));
		// calculate distance
		// draw_line(player.pos_modif, intersec);
		ray_dir -= 60 * PI / 180 / map_size.width;
		if (ray_dir < 0)
			ray_dir += 2 * PI;
		i++;
	}
	printf("how many rays are there %d\n", i);
}

int	main(void)
{
	t_cub		data;

	init_map_size(&(data.map_size));
	data.player = get_initial_player_info(worldMap, data.map_size.tile_size);
	printf("player_pos.x = %f\n", data.player.pos.x);
	printf("player_pos.y = %f\n", data.player.pos.y);
	printf("player_dir.x = %f\n", data.player.dir);
	printf("player_pos_modified.x = %f\n", data.player.pos_modif.x);
	printf("player_pos_modified.y = %f\n", data.player.pos_modif.y);
	printf("player_dir_modified = %f\n", data.player.dir_modif);
	printf("Below are the intersec points\n");
	cast_ray(data.rays, worldMap, data.player, data.map_size);
}
