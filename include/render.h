/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:57:11 by sawang            #+#    #+#             */
/*   Updated: 2023/08/31 20:04:31 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3D.h"
# include "raycast.h"

# ifndef BPP
#  define BPP 4
# endif

//error handling of render
typedef enum e_render_exit_code
{
	RENDER_SUCCESS,
	MLX_CANNOT_INIT,
	TEXTURE_CANNOT_LOAD,
	TEXTURE_NOT_SQUARE,
	TEXTURE_SMALLER_THAN_TILE,
	IMG_CANNOT_CREATE,
	IMG_CANNOT_CONVERT_FROM_TEXTURE,
	IMG_CANNOT_DISPLAY,
	UNKNOWN_ERROR
}			t_render_exit_code;

t_render_exit_code	render_error_print(t_render_exit_code render_error_code);
void				quit(t_cub *data, t_render_exit_code render_exit_code);

// check texture
t_render_exit_code	wall_texture_load(mlx_texture_t *wall_tex[], char *wall[]);
t_render_exit_code	wall_is_square(mlx_texture_t *wall_tex[]);
t_render_exit_code	wall_larger_than_tile(mlx_texture_t *wall_tex[]);

// draw vertical line
void				draw_verti_line(mlx_image_t *g_img, double x, \
	t_vec draw_range, u_int32_t color);

// draw texture
void				draw_texture(mlx_image_t *g_img, double x, t_ray ray, \
	mlx_texture_t *wall_tex[]);

// render
void				render(mlx_image_t *g_img, t_cub *data, keys_t key);
t_render_exit_code	start_render(t_cub *data);

#endif
