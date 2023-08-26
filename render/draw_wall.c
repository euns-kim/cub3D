/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:20:51 by sawang            #+#    #+#             */
/*   Updated: 2023/08/26 16:53:32 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3D.h"
#include "raycast.h"

// static void	init_delta(t_delta *delta)
// {
// 	delta->dx = 0;
// 	delta->dy = 0;
// 	delta->p = 0;
// 	delta->xi = 1;
// 	delta->yi = 1;
// }

//need to get texture later
void	draw_wall(mlx_image_t *g_img, t_map_size map_size, t_ray *rays)
{
	int	i;

	i = 0;
	while (i < map_size.width)
	{
		// draw_sky
		draw_verti_line(g_img, i, 0, rays[i].wall_top, 0x89cff0);
		// draw_wall
		draw_verti_line(g_img, i, rays[i].wall_top, rays[i].wall_bottom, 0xF4C2C2);
		// draw_floor
		draw_verti_line(g_img, i, rays[i].wall_bottom, g_img->height, 0xD1F3C5);
		i++;
	}

}
