/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 18:59:10 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/29 20:35:33 by sawang           ###   ########.fr       */
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
	bool	graphic_data_parsed;
	int		player_cnt;
	char	**tmp_map;
}	t_parser_data;

typedef struct s_map_data
{
	char		*wall[4];
	int32_t		floor_color;
	int32_t		ceiling_color;
	uint32_t	map_width;
	uint32_t	map_height;
	char		**map;
}	t_map_data;

// // parser.c
// t_parser_exit_code	parser(t_map_data *map_data, const char *path);
// void				parse_graphic_data(char *line, t_parser_data *parser_data, t_map_data *map_data);
// char				*check_parsing_status_and_advance(char *line, t_parser_data *parser_data, t_map_data *map_data);

// // parser_2.c
// t_type				catch_type(char *line, int *idx);
// t_parser_exit_code	parse_texture(t_type type, char *line, t_parser_data *parser_data, t_map_data *map_data);

// // parser_utils.c
// void				init_data(t_parser_data *parser_data, t_map_data *map_data);
// void				open_map_file(const char *path, int *map_fd);
// bool				check_if_graphic_data_parsed(t_parser_data *parser_data, t_map_data *map_data);
// char				*cub_strdup(const char *line);
// bool				is_empty_line(char *line);

// // parser_utils_2.c
// int					extension_check(const char *path, const char *extension);
// t_parser_exit_code	string_slicer_ws(char *line, t_parser_data *parser_data);

// // parser_error.c
// void				parser_free_before_exit(t_parser_data *parser_data, t_map_data *map_data);
// void				error_handler(t_parser_data *parser_data, \
// 					t_map_data *map_data, t_parser_exit_code error);

// // parser_free.c
// void				free_p(void *p);

#endif
