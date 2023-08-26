/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:57:11 by sawang            #+#    #+#             */
/*   Updated: 2023/08/26 17:37:25 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"
# include "raycast.h"

//for draw_line function
// typedef struct s_delta
// {
// 	int	dx;
// 	int	dy;
// 	int	xi;
// 	int	yi;
// 	int	p;
// }				t_delta;

// general draw_line function
// void	draw_line(mlx_image_t *g_img, t_vec p1, t_vec p2, t_delta delta, uint32_t color);

//error handling of render
typedef enum e_render_exit_code
{
	RENDER_SUCCESS,
	MLX_CANNOT_INIT,
	TEXTURE_CANNOT_LOAD,
	IMG_CANNOT_CREATE,
	IMG_CANNOT_CONVERT_FROM_TEXTURE,
	IMG_CANNOT_DISPLAY,
	UNKNOWN_ERROR
}			t_render_exit_code;

t_render_exit_code	render_error(t_cub_exit_code render_error_code, mlx_t *mlx);

// draw vertical line
void	draw_verti_line(mlx_image_t *g_img, double x, double y1, double y2, u_int32_t color);

#endif
