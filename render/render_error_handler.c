/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_error_handler.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 17:15:55 by sawang            #+#    #+#             */
/*   Updated: 2023/08/26 19:34:23 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3D.h"

#include <stdio.h>

t_render_exit_code	render_error_print(t_render_exit_code render_error_code)
{
	if (render_error_code == MLX_CANNOT_INIT)
	{
		printf("Error: mlx error\n");
		return (render_error_code);
	}
	else if (render_error_code == TEXTURE_CANNOT_LOAD)
		printf("Error\n: cannot load the texture from file\n");
	else if (render_error_code == IMG_CANNOT_CREATE)
		printf("Error: cannot create image\n");
	else if (render_error_code == IMG_CANNOT_CONVERT_FROM_TEXTURE)
		printf("Error: cannot convert texture to a displayable image\n");
	else if (render_error_code == IMG_CANNOT_DISPLAY)
		printf("Error: cannot display image\n");
	else
		printf("Error: unknown error\n");
	// mlx_terminate(mlx);
	return (render_error_code);
}

void	quit(t_cub *data, t_render_exit_code render_exit_code)
{

	// free_map(data->map_data);//do I need to free??
	if (render_exit_code == MLX_CANNOT_INIT)
		exit (CUB_FAILURE);
	else if (!render_exit_code) //render_exit_code == RENDER_SUCCESS
	{
		mlx_delete_image(data->mlx, data->g_img_full);
		// mlx_delete_texture(data->mlx, texture);
		mlx_terminate(data->mlx);
		exit (CUB_SUCCESS);
	}
	else
	{
		// delete image??
		// delete texture??
		mlx_terminate(data->mlx);
		exit (CUB_FAILURE);
	}
}
