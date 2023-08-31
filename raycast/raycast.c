/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:32:22 by sawang            #+#    #+#             */
/*   Updated: 2023/08/31 19:34:53 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "raycast.h"

#include <stdio.h>

void	cast_ray(t_ray *rays, t_map_data map_data, t_player player, \
	t_map_size map_size)
{
	int		i;
	double	ray_dir;
	double	dist_to_proj;

	dist_to_proj = WIDTH / 2 / tan(FOV / 2 * PI / 180);
	i = 0;
	ray_dir = player.dir_modif + FOV / 2 * PI / 180;
	if (ray_dir > 2 * PI)
		ray_dir -= 2 * PI;
	while (i < map_size.width)
	{
		rays[i].ray_dir = ray_dir;
		determine_intersec(&rays[i], map_data, map_size.tile_size, player);
		rays[i].dist = calc_dist(player.pos_modif.x, rays[i].intersec.x, \
			ray_dir) * cos(player.dir_modif - rays[i].ray_dir);
		rays[i].wall_height = map_size.tile_size / rays[i].dist * dist_to_proj;
		rays[i].wall_top = (HEIGHT - rays[i].wall_height) / 2;
		rays[i].wall_bottom = (HEIGHT + rays[i].wall_height) / 2;
		ray_dir -= FOV * PI / 180 / map_size.width;
		if (ray_dir < 0)
			ray_dir += 2 * PI;
		i++;
	}
}
