/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 22:34:03 by sawang            #+#    #+#             */
/*   Updated: 2023/08/22 22:34:03 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "raycast.h"

#include <stdio.h>

t_vec	get_increment_x_intersec(double ray_dir, int tile_size)
{
	t_vec	increment;

	increment.x = tile_size;
	increment.y = tile_size;
	if (ray_dir > 0 && ray_dir < PI) //facing up
		increment.y *= -1;
	else if (ray_dir > PI && ray_dir < 2 * PI)//facing down
		increment.y *= 1;
	increment.x = (-1) * increment.y / tan(ray_dir);
	return (increment);
}

t_vec	check_horiz_intersec(int worldMap[mapHeight][mapWidth], \
	int tile_size, t_player player, double ray_dir)
{
	t_vec	intersec;
	t_vec	increment;

	intersec.x = INFINITY;
	intersec.y = player.pos_modif.y;
	if (ray_dir == 0 || ray_dir == PI)
		return (intersec);
	if (ray_dir > 0 && ray_dir < PI)//face up
		intersec.y = floor(player.pos_modif.y / tile_size) * tile_size - 1; //round down
	else
		intersec.y = floor(player.pos_modif.y / tile_size) * tile_size + tile_size; // round down
	intersec.x = player.pos_modif.x + (player.pos_modif.y - intersec.y) / \
		tan(ray_dir);
	increment = get_increment_x_intersec(ray_dir, tile_size);
	while ((int)(intersec.y / tile_size) < mapHeight && (int)(intersec.y / tile_size) >=0  && \
		(int)(intersec.x / tile_size) < mapWidth && (int)(intersec.x / tile_size) >= 0 && \
		worldMap[(int)(intersec.y / tile_size)] \
		[(int)(intersec.x / tile_size)] != 1) //round down, check if the intersec is a wall
	{
		intersec.x += increment.x;
		intersec.y += increment.y;
	}
	/** printf("the hit point of [horiz] at the map is [%d][%d]\n", \
	// 	(int)(intersec.y / tile_size), (int)(intersec.x / tile_size));
	**/
	return (intersec);
}

t_vec	get_increment_y_intersec(double ray_dir, int tile_size)
{
	t_vec	increment;

	increment.x = tile_size;
	increment.y = tile_size;
	if (ray_dir > PI / 2 && ray_dir < 3 * PI / 2) //facing left
		increment.x *= -1;
	else if ((ray_dir < PI / 2 && ray_dir > 0) || (ray_dir > 3 * PI / 2 && ray_dir < 2 * PI))//facing right
		increment.x *= 1;
	increment.y = (-1) * increment.x * tan(ray_dir);
	return (increment);
}

t_vec	check_verti_intersec(int worldMap[mapHeight][mapWidth], \
	int tile_size, t_player player, double ray_dir)
{
	t_vec	intersec;
	t_vec	increment;

	intersec.y = INFINITY;
	intersec.x = player.pos_modif.x;
	if (ray_dir == PI / 2 || ray_dir == 3 * PI / 2)
		return (intersec);
	if (ray_dir > PI / 2 && ray_dir < 3 * PI / 2) //facing left
		intersec.x = floor(player.pos_modif.x / tile_size) * tile_size - 1; //round down
	else
		intersec.x = floor(player.pos_modif.x / tile_size) * tile_size + tile_size; //round down
	intersec.y = player.pos_modif.y + (player.pos_modif.x - intersec.x) * \
		tan(ray_dir);
	increment = get_increment_y_intersec(ray_dir, tile_size);
	while ((int)(intersec.y / tile_size) < mapHeight && (int)(intersec.y / tile_size) >=0  && \
		(int)(intersec.x / tile_size) < mapWidth && (int)(intersec.x / tile_size) >=0 && \
		worldMap[(int)(intersec.y / tile_size)] \
		[(int)(intersec.x / tile_size)] != 1) //round down, check if the intersec is a wall
	{
		intersec.x += increment.x;
		intersec.y += increment.y;
	}
	/** printf("the hit point of [verti] at the map is [%d][%d]\n", \
	// 	(int)(intersec.y / tile_size), (int)(intersec.x / tile_size));
	**/
	return (intersec);
}

void	determine_intersec(t_ray *ray, int worldMap[mapHeight][mapWidth], int tile_size, t_player player)
{
	t_vec	horiz_intersec;
	t_vec	verti_intersec;

	horiz_intersec = check_horiz_intersec(worldMap, tile_size, player, ray->ray_dir);
	verti_intersec = check_verti_intersec(worldMap, tile_size, player, ray->ray_dir);
	if (horiz_intersec.x == INFINITY && verti_intersec.y == INFINITY)
	{
		ray->intersec.x = INFINITY;
		ray->intersec.y = INFINITY;
	}
	else if (horiz_intersec.x == INFINITY)
		ray->intersec = verti_intersec;
	else if (verti_intersec.y == INFINITY)
		ray->intersec = horiz_intersec;
	else if (fabs((player.pos_modif.x - horiz_intersec.x) / cos(ray->ray_dir)) < \
		fabs((player.pos_modif.x - verti_intersec.x) / cos(ray->ray_dir)))
	{
		ray->side = 0; //hit the horizontal wall. checking NWSE with player.dir_modif or ray_dir ??
		ray->intersec = horiz_intersec;
	}
	else
	{
		ray->side = 1; //hit the vertical wall. checking NWSE with player.dir_modif or ray_dir ??
		ray->intersec = verti_intersec;
	}
}
