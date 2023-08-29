/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:03:14 by sawang            #+#    #+#             */
/*   Updated: 2023/08/29 14:55:43 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3D.h"
#include "raycast.h"

static void	get_map_data(t_map_data *map_data)
{
	map_data->ceiling_color = 0x89cff0FF;
	map_data->floor_color = 0xD1F3C5FF;
	// printf("NorthWall located at %p\n", map_data->wall[0]);
	// printf("EastWall located at %p\n", map_data->wall[1]);
	// printf("SouthWall located at %p\n", map_data->wall[2]);
	// printf("WestWall located at %p\n", map_data->wall[3]);
}

int	main(void)
{
	t_cub				data;
	t_render_exit_code	render_exit_code;

	get_map_data(&(data.map_data));
	init_map_size(&(data.map_size));
	data.player = get_initial_player_info(worldMap, data.map_size.tile_size);
	render_exit_code = start_render(&data);
	quit(&data, render_exit_code);
}
