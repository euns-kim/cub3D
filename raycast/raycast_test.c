/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1011/08/18 16:01:11 by sawang            #+#    #+#             */
/*   Updated: 2023/08/22 22:34:39 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/cub3D.h"
#include "raycast_mini.h"

#include <stdio.h>

//later get the mapWidth and mapHeight from the map file
// they are the index i and j of the map
#define mapWidth 24
#define mapHeight 26
// #define screenWidth 610
// #define screenHeight 180



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

t_vec	determine_intersec(int worldMap[mapHeight][mapWidth], int tile_size, t_player player, double ray_dir)
{
	t_vec	horiz_intersec;
	t_vec	verti_intersec;
	t_vec	intersec;

	horiz_intersec = check_horiz_intersec(worldMap, tile_size, player, ray_dir);
	verti_intersec = check_verti_intersec(worldMap, tile_size, player, ray_dir);
	if (horiz_intersec.x == INFINITY && verti_intersec.y == INFINITY)
	{
		intersec.x = INFINITY;
		intersec.y = INFINITY;
		return (intersec);
	}
	if (horiz_intersec.x == INFINITY)
		return (verti_intersec);
	if (verti_intersec.y == INFINITY)
		return (horiz_intersec);
	if (fabs((player.pos_modif.x - horiz_intersec.x) / cos(ray_dir)) < \
		fabs((player.pos_modif.x - verti_intersec.x) / cos(ray_dir)))
	{
			// ray.side = 0; //hit the horizontal wall. checking NWSE with player.dir_modif or ray_dir ??
		return (horiz_intersec);
	}
	// ray.side = 1; //hit the vertical wall. checking NWSE with player.dir_modif or ray_dir ??
	return (verti_intersec);
}

// loop through the screen width
// FOV = 60 degree
// since the width is 640, the FOV is 60 degree,
// the angle between each ray is 60 / 640
// the most left ray is player.dir_modif + 30 degree
// the most right ray is player.dir_modif - 30 degree
// the increment is 60 / 640
// the ray is the line from the player to the intersec
// the intersec is the point where the ray hits the wall
void	cast_ray(int worldMap[mapHeight][mapWidth], t_player player, \
	t_minimap minimap)
{
	int		i;
	double	ray_dir;
	t_vec	intersec;

	i = 0;
	ray_dir = player.dir_modif + 30 * PI / 180;
	if (ray_dir > 2 * PI)
		ray_dir -= 2 * PI;
	// do I need check the angle after rotate? or just check the angle before rotate?
	// if (ray_dir < 0)
		// ray_dir += 2 * PI;
	//calculate clockwise ray
	// while (i < minimap.width)
	while (i < WIDTH)
	{
		printf("ray_dir = %f\t", ray_dir);
		// printf("ray_dir in degree = %f\n", ray_dir * 180 / PI);
		intersec = determine_intersec(worldMap, minimap.tile_size, player, ray_dir);
		printf("the hit point at the map is [%d][%d]\n", \
			(int)(intersec.y / minimap.tile_size), (int)(intersec.x / minimap.tile_size));
		// draw_line(player.pos_modif, intersec);
		// ray_dir -= 60 * PI / 180 / minimap.width;
		ray_dir -= 60 * PI / 180 / WIDTH;
		if (ray_dir < 0)
			ray_dir += 2 * PI;
		i++;
	}
}

int	main(void)
{
	t_data		data;

	init_minimap(&(data.minimap));
	data.player = get_initial_player_info(worldMap, data.minimap.tile_size);
	printf("player_pos.x = %f\n", data.player.pos.x);
	printf("player_pos.y = %f\n", data.player.pos.y);
	printf("player_dir.x = %f\n", data.player.dir);
	printf("player_pos_modified.x = %f\n", data.player.pos_modif.x);
	printf("player_pos_modified.y = %f\n", data.player.pos_modif.y);
	printf("player_dir_modified = %f\n", data.player.dir_modif);
	printf("Below are the intersec points\n");
	// cast_ray(worldMap, data.player, data.minimap);
}
