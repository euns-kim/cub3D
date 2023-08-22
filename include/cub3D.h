/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:54:49 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/18 21:26:22 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef WIDTH
#  define WIDTH 640
# endif

# ifndef HEIGHT
#  define HEIGHT 480
# endif

# ifndef TILE_SIZE
#  define TILE_SIZE 64
# endif

// # include "MLX42.h"
// # include "libft.h"
// # include "get_next_line.h"
// # include "parser.h"
# include "raycast.h"
# include "hook.h"

typedef enum e_cub_exit_code
{
	CUB_SUCCESS,
	CUB_INVALID_ARGUMENT
}	t_cub_exit_code;

typedef struct s_cub
{
	// mlx
	// img for large map
	// img for minimap
	// img for rays in minimap
	// t_map_data	map_data;
	t_player	player;
	t_map_size	map_size;
	// t_map_size	minimap_size;
	t_ray		rays[WIDTH];


}	t_cub;

#endif
