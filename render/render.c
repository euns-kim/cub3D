/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:46:31 by sawang            #+#    #+#             */
/*   Updated: 2023/08/31 20:00:00 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3D.h"
#include "raycast.h"

void	draw(mlx_image_t *g_img, t_ray *rays, t_map_data map_data, \
	mlx_texture_t *wall_tex[])
{
	int		i;
	t_vec	ceiling_range;
	t_vec	floor_range;

	i = 0;
	while (i < WIDTH)
	{
		ceiling_range.x = 0;
		ceiling_range.y = rays[i].wall_top;
		draw_verti_line(g_img, i, ceiling_range, map_data.ceiling_color);
		draw_texture(g_img, i, rays[i], wall_tex);
		floor_range.x = rays[i].wall_bottom;
		floor_range.y = HEIGHT;
		draw_verti_line(g_img, i, floor_range, map_data.floor_color);
		i++;
	}
}

void	render(mlx_image_t *g_img, t_cub *data, keys_t key)
{
	update_hook_input(data->player, &data->hook_input, key);
	update_player(&data->player, &data->hook_input, data->map_data);
	cast_ray(data->rays, data->map_data, data->player, data->map_size);
	draw(g_img, data->rays, data->map_data, data->wall_tex);
}

t_render_exit_code	start_render(t_cub *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "Cub21", true);
	if (!data->mlx)
		return (render_error_print(MLX_CANNOT_INIT));
	if (wall_texture_load(data->wall_tex, data->map_data.wall))
		return (render_error_print(TEXTURE_CANNOT_LOAD));
	if (wall_is_square(data->wall_tex))
		return (render_error_print(TEXTURE_NOT_SQUARE));
	if (wall_larger_than_tile(data->wall_tex))
		return (render_error_print(TEXTURE_SMALLER_THAN_TILE));
	data->g_img_full = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->g_img_full)
		return (render_error_print(IMG_CANNOT_CREATE));
	if (mlx_image_to_window(data->mlx, data->g_img_full, 0, 0))
		return (render_error_print(IMG_CANNOT_DISPLAY));
	render(data->g_img_full, data, 0);
	mlx_loop_hook(data->mlx, (void (*)(void *))hook, data);
	mlx_loop(data->mlx);
	return (RENDER_SUCCESS);
}
