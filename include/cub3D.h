/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:54:49 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/31 14:34:07 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # include "MLX42.h"
# include "libft.h"
# include "get_next_line.h"
# include "parser.h"

typedef enum e_cub_exit_code
{
	CUB_SUCCESS,
	CUB_INVALID_ARGUMENT,
	CUB_WRONG_EXTENSION
}	t_cub_exit_code;

typedef struct s_cub
{
	t_map_data	map_data;
}	t_cub;

#endif
