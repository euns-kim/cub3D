/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:59:30 by sawang            #+#    #+#             */
/*   Updated: 2023/08/31 20:00:29 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "render.h"

t_render_exit_code	wall_texture_load(mlx_texture_t *wall_tex[], char *wall[])
{
	wall_tex[NORTH] = mlx_load_png(wall[NORTH]);
	wall_tex[EAST] = mlx_load_png(wall[EAST]);
	wall_tex[SOUTH] = mlx_load_png(wall[SOUTH]);
	wall_tex[WEST] = mlx_load_png(wall[WEST]);
	if (!wall_tex[NORTH] || !wall_tex[EAST] || \
		!wall_tex[SOUTH] || !wall_tex[WEST])
		return (TEXTURE_CANNOT_LOAD);
	return (RENDER_SUCCESS);
}

t_render_exit_code	wall_is_square(mlx_texture_t *wall_tex[])
{
	if (wall_tex[NORTH]->width != wall_tex[NORTH]->height || \
		wall_tex[EAST]->width != wall_tex[EAST]->height || \
		wall_tex[SOUTH]->width != wall_tex[SOUTH]->height || \
		wall_tex[WEST]->width != wall_tex[WEST]->height)
		return (TEXTURE_NOT_SQUARE);
	return (RENDER_SUCCESS);
}

t_render_exit_code	wall_larger_than_tile(mlx_texture_t *wall_tex[])
{
	if (wall_tex[NORTH]->width < TILE_SIZE || \
		wall_tex[EAST]->width < TILE_SIZE || \
		wall_tex[SOUTH]->width < TILE_SIZE || \
		wall_tex[WEST]->width < TILE_SIZE)
		return (TEXTURE_SMALLER_THAN_TILE);
	return (RENDER_SUCCESS);
}
