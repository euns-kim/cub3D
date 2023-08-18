/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:54:49 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/18 18:39:32 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include "MLX42.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct s_map_data
{
	mlx_texture_t*	wall_north;
	mlx_texture_t*	wall_west;
	mlx_texture_t*	wall_south;
	mlx_texture_t*	wall_east;
	int32_t			ground_color;
	int32_t			ceiling_color;
	char			**map;
}	t_map_data;

#endif