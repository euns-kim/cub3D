/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1011/08/18 16:01:11 by sawang            #+#    #+#             */
/*   Updated: 2023/08/18 22:59:19 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast_mini.h"

#include <stdio.h>

//later get the mapWidth and mapHeight from the map file
// they are the index i and j of the map
#define mapWidth 24
#define mapHeight 26
// #define screenWidth 610
// #define screenHeight 180

char worldMap[mapHeight][mapWidth]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,'N',0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

t_vec	get_player_pos(int i, int j)
{
	t_vec	pos;

	pos.x = i;
	pos.y = j;
	return (pos);
}

double	get_player_dir(int i, int j)
{
	double	dir;

	dir = 0;
	if (worldMap[j][i] == 'N')
		dir = 90 * PI / 180;
	else if (worldMap[j][i] == 'S')
		dir = 270 * PI / 180;
	else if (worldMap[j][i] == 'E')
		dir = 0;
	else if (worldMap[j][i] == 'W')
		dir = 180 * PI / 180;
	return (dir);
}

t_player	get_initial_player_info(char worldMap[mapHeight][mapWidth], \
	int tile_size)
{
	int			i;
	int			j;
	t_player	player;

	j = 0;
	player.pos.x = 0;
	player.pos.y = 0;
	player.dir = 0;
	player.pos_modif.x = 0;
	player.pos_modif.y = 0;
	player.dir_modif = 0;
	while (j < mapHeight)
	{
		i = 0;
		while (i < mapWidth)
		{
			if (worldMap[j][i] == 'N' || worldMap[j][i] == 'S' || \
				worldMap[j][i] == 'E' || worldMap[j][i] == 'W')
			{
				player.pos = get_player_pos(i, j);
				player.dir = get_player_dir(i, j);
				player.pos_modif.x = (player.pos.x + 0.5) * tile_size;
				player.pos_modif.y = (player.pos.y + 0.5) * tile_size;
				player.dir_modif = player.dir;
				return (player);
			}
			i++;
		}
		j++;
	}
	return (player);
}

void	init_minimap(t_minimap *minimap)
{
	minimap->height = HEIGHT;
	minimap->tile_size = HEIGHT / mapHeight;
	minimap->width = minimap->tile_size * mapWidth;
	printf("minimap_height = %d\n", minimap->height);
	printf("minimap_width = %d\n", minimap->width);
	printf("minimap_tile_size = %d\n", minimap->tile_size);
}

void	update_player_info(t_player *player, t_input *input)
{
	player->pos_modif.x = player->pos.x + input->horizontal_move;
	player->pos_modif.y = player->pos.y + input->vertical_move;
	player->dir_modif = player->dir + input->rotated;
}

t_vec	get_increment_x_intersec(double dir_modif, int tile_size)
{
	t_vec	increment;

	increment.x = tile_size;
	increment.y = tile_size;
	if (dir_modif > 0 && dir_modif <= PI / 2)
	{
		increment.y *= -1;
		increment.x = increment.y / tan(dir_modif);
	}
	else if (dir_modif > PI / 2 && dir_modif < PI)
	{
		increment.y *= -1;
		increment.x = increment.y / tan(PI - dir_modif);
	}
	else if (dir_modif > PI && dir_modif <= 1.5 * PI)
	{
		increment.y *= 1;
		increment.x = -1 * increment.y / tan(dir_modif - PI);
	}
	else if (dir_modif > 1.5 * PI && dir_modif < 2 * PI)
	{
		increment.y *= 1;
		increment.x = increment.y / tan(2 * PI - dir_modif);
	}
	return (increment);
}

t_vec	check_horiz_intersec(char worldMap[mapHeight][mapWidth], \
	t_player player, int tile_size)
{
	t_vec	intersec;
	t_vec	increment;

	intersec.x = INFINITY;
	intersec.y = player.pos_modif.y;
	if (player.dir_modif == 0 || player.dir_modif == PI)
		return (intersec);
	if (player.dir_modif > 0 && player.dir_modif < PI)
		intersec.y = floor(player.pos_modif.y / tile_size) * tile_size - 1; //round down
	else
		intersec.y = floor(player.pos_modif.y / tile_size) * tile_size + tile_size; // round down
	intersec.x = player.pos_modif.x + (player.pos_modif.y - intersec.y) / \
		tan(player.dir_modif);
	increment = get_increment_x_intersec(player.dir_modif, tile_size);
	while (worldMap[(int)floor(intersec.y / tile_size)] \
		[(int)floor(intersec.x / tile_size)] != 1) //round down, check if the intersec is a wall
	{
		intersec.x += increment.x;
		intersec.y += increment.y;
	}
	return (intersec);
}

t_vec	get_increment_y_intersec(double dir_modif, int tile_size)
{
	t_vec	increment;

	increment.x = tile_size;
	increment.y = tile_size;
	if (dir_modif >= 0 && dir_modif < PI / 2)
	{
		increment.x *= 1;
		increment.y = -1 * increment.x * tan(dir_modif);
	}
	else if (dir_modif > PI / 2 && dir_modif < PI)
	{
		increment.x *= -1;
		increment.y = increment.x * tan(PI - dir_modif);
	}
	else if (dir_modif >= PI && dir_modif < 1.5 * PI)
	{
		increment.x *= -1;
		increment.y = -1 * increment.x * tan(dir_modif - PI);
	}
	else if (dir_modif > 1.5 * PI && dir_modif < 2 * PI)
	{
		increment.x *= 1;
		increment.y = increment.x * tan(2 * PI - dir_modif);
	}
	return (increment);
}

t_vec	check_verti_intersec(char worldMap[mapHeight][mapWidth], \
	t_player player, int tile_size)
{
	t_vec	intersec;
	t_vec	increment;

	intersec.y = INFINITY;
	intersec.x = player.pos_modif.x;
	if (player.dir_modif == PI / 2 || player.dir_modif == 1.5 * PI)
		return (intersec);
	if (player.dir_modif > PI / 2 && player.dir_modif < 1.5 * PI) //facing left
		intersec.x = floor(player.pos_modif.x / tile_size) * tile_size - 1; //round down
	else
		intersec.x = floor(player.pos_modif.x / tile_size) * tile_size + tile_size; //round down
	intersec.y = player.pos_modif.y + (player.pos_modif.x - intersec.x) * \
		tan(player.dir_modif);
	increment = get_increment_y_intersec(player.dir_modif, tile_size);
	while (worldMap[(int)floor(intersec.y / tile_size)] \
		[(int)floor(intersec.x / tile_size)] != 1) //round down, check if the intersec is a wall
	{
		intersec.x += increment.x;
		intersec.y += increment.y;
	}
	return (intersec);
}

t_vec	determine_intersec(char worldMap[mapHeight][mapWidth], t_player player, double ray_dir, int tile_size)
{
	t_vec	horiz_intersec;
	t_vec	verti_intersec;
	t_vec	intersec;

	horiz_intersec = check_horiz_intersec(worldMap, player, tile_size);
	verti_intersec = check_verti_intersec(worldMap, player, tile_size);
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
	// if (sqrt(pow(player.pos_modif.x - horiz_intersec.x, 2) + \
	// 	pow(player.pos_modif.y - horiz_intersec.y, 2)) < \
	// 	sqrt(pow(player.pos_modif.x - verti_intersec.x, 2) + \
	// 	pow(player.pos_modif.y - verti_intersec.y, 2)))
	if (fabs(player.pos_modif.x - horiz_intersec.x) / fabs(cos(player.dir_modif)) < \
		fabs(player.pos_modif.x - verti_intersec.x) / fabs(cos(player.dir_modif)))
		return (horiz_intersec);
	return (verti_intersec);
}

// loop through the screen width
// FOV = 60 degree
// since the width is 640, the FOV is 60 degree, the angle between each ray is 60 / 640
// the first ray is player.dir_modif - 30 degree
// the last ray is player.dir_modif + 30 degree
// the increment is 60 / 640
// the ray is the line from the player to the intersec
// the intersec is the point where the ray hits the wall
void	cast_ray(char worldMap[mapHeight][mapWidth], t_player player, \
	t_minimap minimap)
{
	int		i;
	double	ray_dir;
	t_vec	intersec;

	i = 0;
	ray_dir = player.dir_modif - 30 * PI / 180;
	while (i < minimap.width)
	{
		intersec = determine_intersec(worldMap, player, ray_dir, minimap.tile_size);
		printf("intersec.x = %f\n", intersec.x);
		printf("intersec.y = %f\n", intersec.y);
		draw_line(player.pos_modif, intersec);
		ray_dir += 60 * PI / 180 / minimap.width;
		i++;
	}
}


int	main(void)
{
	t_player	player;
	t_data		data;

	init_minimap(&(data.minimap));
	data.player = get_initial_player_info(worldMap, data.minimap.tile_size);


	printf("player_pos.x = %f\n", player.pos.x);
	printf("player_pos.y = %f\n", player.pos.y);
	printf("player_dir.x = %f\n", player.dir);
	printf("player_pos_modified.x = %f\n", player.pos_modif.x);
	printf("player_pos_modified = %f\n", player.pos_modif.y);
	printf("player_dir_modified = %f\n", player.dir_modif);
}
