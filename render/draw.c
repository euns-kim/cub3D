/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:20:51 by sawang            #+#    #+#             */
/*   Updated: 2023/08/28 22:57:44 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3D.h"
#include "raycast.h"
#include <assert.h>

// static void	init_delta(t_delta *delta)
// {
// 	delta->dx = 0;
// 	delta->dy = 0;
// 	delta->p = 0;
// 	delta->xi = 1;
// 	delta->yi = 1;
// }

t_type	determine_wall(double ray_dir, int side)
{
	if (side == 0 && ray_dir > 0 && ray_dir < PI)
		return (NORTH);
	else if (side == 0 && ray_dir > PI && ray_dir < 2 * PI)
		return (SOUTH);
	else if (side == 1 && ray_dir > PI / 2 && ray_dir < 3 * PI / 2)
		return (WEST);
	else if (side == 1 && ((ray_dir > 0 && ray_dir < PI / 2) || (ray_dir > 3 * PI / 2 && ray_dir < 2 * PI)))
		return (EAST);
	else
		return (NORTH);
}

int	determine_tex_x(t_vec intersec, t_type wall_type, mlx_texture_t *texture_to_draw)
{
	int	tex_x;

	if (wall_type == NORTH)
		tex_x = (int)intersec.x % texture_to_draw->width;
	else if (wall_type == SOUTH)
	{
		tex_x = texture_to_draw->width - ((int)intersec.x % texture_to_draw->width) - 1;
	}
	else if (wall_type == WEST)
	{
		tex_x = texture_to_draw->width - ((int)intersec.y % texture_to_draw->width) - 1;
		// assert(tex_x < (int)texture_to_draw->width);
	}
	else if (wall_type == EAST)
		tex_x = (int)intersec.y % texture_to_draw->width;
	else
		tex_x = 0;
	printf("howhowhow tex_x = %d\n", tex_x);
	return (tex_x);
}

int	determine_tex_y(t_ray ray, mlx_texture_t *texture_to_draw, int img_j)
{
	int	tex_y;

	tex_y = (img_j - ray.wall_top) * texture_to_draw->height / ray.wall_height;
	return (tex_y);
}

void	draw_texture(mlx_image_t *g_img, double x, t_ray ray, mlx_texture_t *walls[])
// void	draw_texture(t_ray ray, mlx_texture_t *walls[])
{
	t_type			wall_type;
	mlx_texture_t	*texture_to_draw;
	int				tex_x;
	int				tex_y;
	double			img_j;

	printf("draw_texture\n");
	printf("NorthWall located at %p\n", walls[0]);
	printf("EastWall located at %p\n", walls[1]);
	printf("SouthWall located at %p\n", walls[2]);
	printf("WestWall located at %p\n", walls[3]);
	wall_type = determine_wall(ray.ray_dir, ray.side);
	printf("wall_type = %d\n", wall_type);
	texture_to_draw = walls[wall_type];
	printf("texture_to_draw = %p\n", texture_to_draw);
	tex_x = determine_tex_x(ray.intersec, wall_type, texture_to_draw);
	printf("tex_x = %d\n", tex_x);
	img_j = 0;
	while (img_j < HEIGHT)
	{
		//inside determine_tex_y, check if the wall_top < 0 and wall_bottom > HEIGHT
		if (img_j > ray.wall_top && img_j < ray.wall_bottom)
		{
			tex_y = determine_tex_y(ray, texture_to_draw, img_j);
			// printf("tex_y = %d\n", tex_y);
			g_img->pixels[((uint32_t)img_j * WIDTH + (uint32_t)x) * BPP] = \
				texture_to_draw->pixels[(tex_y * texture_to_draw->width + tex_x) * BPP];
			g_img->pixels[((uint32_t)img_j * WIDTH + (uint32_t)x) * BPP + 1] = \
				texture_to_draw->pixels[(tex_y * texture_to_draw->width + tex_x) * BPP + 1];
			g_img->pixels[((uint32_t)img_j * WIDTH + (uint32_t)x) * BPP + 2] = \
				texture_to_draw->pixels[(tex_y * texture_to_draw->width + tex_x) * BPP + 2];
			g_img->pixels[((uint32_t)img_j * WIDTH + (uint32_t)x) * BPP + 3] = \
				texture_to_draw->pixels[(tex_y * texture_to_draw->width + tex_x) * BPP + 3];
		}
		img_j++;
	}
}

void	draw(mlx_image_t *g_img, t_map_size map_size, t_ray *rays, t_map_data map_data)
{
	int	i;

	(void)map_size;
	i = 0;
	while (i < map_size.width)
	{
		// draw_sky
		// draw_verti_line(g_img, i, 0, rays[i].wall_top, 0x89cff0FF);
		draw_verti_line(g_img, i, 0, rays[i].wall_top, map_data.ceiling_color);
		// draw_wall
		// draw_verti_line(g_img, i, rays[i].wall_top, rays[i].wall_bottom, 0xF4C2C2FF);
		// draw texture for the walls
		printf("draw\n");
		printf("NorthWall located at %p\n", map_data.wall[0]);
		printf("EastWall located at %p\n", map_data.wall[1]);
		printf("SouthWall located at %p\n", map_data.wall[2]);
		printf("WestWall located at %p\n", map_data.wall[3]);
		draw_texture(g_img, i, rays[i], map_data.wall);
		// draw_texture(rays[i], map_data.wall);
		// draw_floor
		// draw_verti_line(g_img, i, rays[i].wall_bottom, g_img->height, 0xD1F3C5FF);
		draw_verti_line(g_img, i, rays[i].wall_bottom, g_img->height, map_data.floor_color);
		i++;
	}
}
