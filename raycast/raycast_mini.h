/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_mini.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:41:41 by sawang            #+#    #+#             */
/*   Updated: 2023/08/22 21:28:04 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_MINI_H
# define RAYCAST_MINI_H

# include <math.h>

typedef struct s_vec
{
	double	x;
	double	y;
}				t_vec;

typedef struct s_player
{
	t_vec	pos;
	double	dir; //dir of the player is looking at in radian
	t_vec	pos_modif;
	double	dir_modif;
}				t_player;

typedef struct s_map_size
{
	int	height;
	int	width;
	int	tile_size;
}				t_map_size;


typedef struct s_ray
{
	double	ray_dir;
	t_vec	intersec;
	int		side;
	double	dist;
	double	wall_height;
	double	wall_top;
	double	wall_bottom;
}				t_ray;

// typedef struct s_data
// {
// 	t_player	player;
// 	 t_input		input;
// 	t_minimap	minimap;
// 	t_ray		ray[WIDTH];
// }				t_data;

#endif
