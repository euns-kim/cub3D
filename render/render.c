/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:46:31 by sawang            #+#    #+#             */
/*   Updated: 2023/08/26 18:04:20 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3D.h"
#include "raycast.h"

void	render(mlx_image_t *g_img, t_cub *data, keys_t key)
{
	updata_hook_input(data->hook_input, key);
	fdf_memset(g_img->pixels, 0, g_img->width * g_img->height * sizeof(int));
	update_player(data->player, data->hook_input);
	ray_cast(data->rays, worldMap, data->player, data->map_size);
	draw_wall(g_img, data->map_size, data->rays);
}

t_cub_exit_code	start_render(t_cub *data)
{
	// (*frame).data = *init_data(&(*frame).data);
	(*data).mlx = mlx_init(WIDTH, HEIGHT, "Cub21", true);
	if (!(*data).mlx)
		return (render_error_handler(MLX_CANNOT_INIT));
	(*data).g_img_full = mlx_new_image((*data).mlx, WIDTH, HEIGHT);
	if (!(*data).g_img_full)
		return (render_error_handler(IMG_CANNOT_CREATE));
	if (mlx_image_to_window((*data).mlx, (*data).g_img_full, 0, 0))
		return (render_error_handler(IMG_CANNOT_DISPLAY));
	// init_map(frame);
	// draw(frame->g_img, &frame->map, &frame->data, 0);
	render((*data).g_img_full, data, 0);
	// mlx_scroll_hook(frame->mlx, (mlx_scrollfunc) scroll_hook, frame);
	// mlx_key_hook(frame->mlx, (mlx_keyfunc) key_hook, frame);
	// mlx_loop_hook((*frame).mlx, (void (*)(void *))hook, frame);
	mlx_loop((*data).mlx);
	// quit(data); //quit outside of start_render???
	return (RENDER_SUCCESS);
}
