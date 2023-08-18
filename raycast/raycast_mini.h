/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_mini.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:41:41 by sawang            #+#    #+#             */
/*   Updated: 2023/08/18 22:49:01 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_MINI_H
# define RAYCAST_MINI_H

# include <math.h>

# ifndef WIDTH
#  define WIDTH 640
# endif

# ifndef HEIGHT
#  define HEIGHT 480
# endif

# ifndef PI
#  define PI 3.1415
# endif

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
	// t_vec	plane;
}				t_player;

// typedef struct s_ray
// {
// 	t_vec	pos;
// 	t_vec	dir;
// }				t_ray;

typedef struct s_minimap
{
	int	height;
	int	width;
	int	tile_size;
}				t_minimap;

typedef struct s_input
{
	int		horizontal_move; //move the player left or right using keys A and D
	int		vertical_move; //move the player forward or backward using keys W and S
	double	rotated; //rotated direction of the player using the arrow keys
}				t_input;

typedef struct s_ray
{
	double	ray_dir;
	t_vec	intersec;
	double	dist;
}				t_ray;

typedef struct s_data
{
	// void	*mlx;
	// void	*img;
	// t_map		map;
	t_player	player;
	t_minimap	minimap;
	t_input		input;
	t_ray		ray;
}				t_data;

#endif
