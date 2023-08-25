/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:59:10 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/25 22:47:25 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include "MLX42.h"
# include "libft.h"
# include "get_next_line.h"

# define WHITESPACES " \t\v\f\r"

typedef enum e_parser_exit_code
{
	PARSER_SUCCESS,
	PARSER_MALLOC_ERROR,
	OPEN_ERROR,
	EMPTY_FILE,
	INVALID_DATA,
	BAD_TEXTURE_EXTENSION,
	TEXTURE_OPEN_ERROR,
	BAD_TEXTURE_SIZE,
	DATA_AMBIGUITY,
	TEXTURE_NOT_LOADED,
	BAD_RGB,
	GRAPHIC_DATA_INCOMPLETE,
	NO_MAP_FOUND,
	EMPTY_LINE_IN_MAP,
	INVALID_ELEMENT,
	MULTIPLE_PLAYER,
	UNCLOSED_MAP
}	t_parser_exit_code;

typedef enum e_type
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
	FLOOR,
	CEILING,
	ERROR
}	t_type;

typedef struct s_parser_data
{
	int		map_fd;
	int		scanner_idx;
	char	*texture_path;
	bool 	graphic_data_parsed;
	int		player_cnt;
	char	**tmp_map;
}	t_parser_data;

typedef struct s_map_data
{
	mlx_texture_t*	wall[4];
	int32_t			floor_color;
	int32_t			ceiling_color;
	uint32_t		map_width;
	uint32_t		map_height;
	char			**map;
}	t_map_data;

#endif