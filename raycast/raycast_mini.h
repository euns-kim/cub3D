/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_mini.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 14:41:41 by sawang            #+#    #+#             */
/*   Updated: 2023/08/18 16:39:36 by sawang           ###   ########.fr       */
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
	t_vec	dir;
	t_vec	plane;
}				t_player;

typedef struct s_ray
{
	t_vec	pos;
	t_vec	dir;
}				t_ray;

typedef struct s_minimap
{
	int	height;
	int	width;
	int	tile_size;
}				t_minimap;


#endif
