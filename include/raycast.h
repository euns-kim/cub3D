/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:41:41 by sawang            #+#    #+#             */
/*   Updated: 2023/08/31 19:36:28 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# ifndef PI
#  define PI 3.1415
# endif

# ifndef FOV
#  define FOV 60
# endif

# include <math.h>

typedef struct s_vec
{
	double	x;
	double	y;
}				t_vec;

typedef struct s_player
{
	t_vec	pos;
	double	dir;
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

/**
 * hit_point calculations
 */
t_vec	get_increment_x_intersec(double ray_dir, int tile_size);
t_vec	check_horiz_intersec(t_map_data map_data, \
	int tilesize, t_player player, double ray_dir);
t_vec	get_increment_y_intersec(double ray_dir, int tile_size);
t_vec	check_verti_intersec(t_map_data map_data, \
	int tilesize, t_player player, double ray_dir);
void	determine_intersec(t_ray *ray, t_map_data map_data, \
	int tilesize, t_player player);

/**
 * raycast
 */
void	cast_ray(t_ray *rays, t_map_data map_data, t_player player, \
	t_map_size map_size);

/**
 * calculate_utils
 */
double	calc_dist(double pos_x, double intersec_x, double ray_dir);

#endif
