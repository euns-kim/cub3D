/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 18:03:14 by sawang            #+#    #+#             */
/*   Updated: 2023/08/26 18:05:44 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3D.h"
#include "raycast.h"

int	main(void)
{
	t_cub	data;
	t_render_exit_code	render_exit_code;

	init_map_size(&(data.map_size));
	data.player = get_initial_player_info(worldMap, data.map_size.tile_size);
	render_exit_code = start_render(&data);
	quit(&data, render_exit_code);
}
