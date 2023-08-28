/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:57:11 by sawang            #+#    #+#             */
/*   Updated: 2023/08/28 21:28:18 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3D.h"
# include "raycast.h"

#ifndef BPP
# define BPP 4
#endif

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

t_render_exit_code	render_error_print(t_render_exit_code render_error_code);
void				quit(t_cub *data, t_render_exit_code render_exit_code);

// draw vertical line
void				draw_verti_line(mlx_image_t *g_img, double x, double y1, double y2, u_int32_t color);

void				draw(mlx_image_t *g_img, t_map_size map_size, t_ray *rays, t_map_data map_data);

t_render_exit_code	start_render(t_cub *data);


//utils
void	*cub_memset(void *b, int c, size_t len);
#endif
