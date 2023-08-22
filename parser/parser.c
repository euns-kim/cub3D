/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:57:35 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/22 22:35:12 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	check_parsing_status(char *line, t_parser_data *parser_data, t_map_data *map_data)
{
	if (parser_data->graphic_data_parsed == false)
		error_handler(parser_data, map_data, GRAPHIC_DATA_INCOMPLETE);
	if (!line) //looping more here?
		error_handler(parser_data, map_data, NO_MAP_FOUND);
}

char	*cub_strdup(const char *line)
{
	int     i;
	char	*line_cpy;

	i = 0;
	line_cpy = ft_calloc(1, ft_strlen(line) + 1);
	if (line_cpy == NULL)
		return (NULL);
	while (line[i] != '\0' && line[i] != '\n')
	{
		line_cpy[i] = line[i];
		i++;
	}
	return (line_cpy);
}

void	parse_graphic_data(char *line, t_parser_data *parser_data, t_map_data *map_data)
{
	char	*line_cpy;
	int		scanner_idx;
	t_type	type;

	line_cpy = cub_strdup(line);
	if (line_cpy == NULL)
		error_handler(parser_data, map_data, PARSER_MALLOC_ERROR);
	scanner_idx = 0;
	type = catch_type(line, &scanner_idx);
	if (type >= NORTH && type <= WEST)
		parse_texture(type, line, &scanner_idx);
	else if (type == FLOOR || type == CEILING)
		parse_rgb(type, line, &scanner_idx);	
}

bool	check_if_graphic_data_parsed(t_parser_data *parser_data, t_map_data *map_data)
{
	if (map_data->wall[NORTH] != NULL && \
	map_data->wall[EAST] != NULL && \
	map_data->wall[SOUTH] != NULL && \
	map_data->wall[WEST] != NULL && \
	map_data->floor_color != -1 && \
	map_data->ceiling_color != -1)
	{
		parser_data->graphic_data_parsed = true;
		return (true);
	}
	return (false);
}

t_parser_exit_code	parser(t_map_data *map_data, const char *path)
{
	t_parser_data		parser_data;
	char				*line;

	init_data(&parser_data, map_data);
	open_map_file(path, &parser_data.map_fd);
	line = get_next_line(parser_data.map_fd);
	if (!line)
		error_handler(&parser_data, map_data, EMPTY_FILE);
	while (line && check_if_graphic_data_parsed(&parser_data, map_data) != true)
	{
		if (line[0] == '\0')
			continue ;
		parse_graphic_data(line, &parser_data, map_data);
		line = get_next_line(parser_data.map_fd);
	}
	check_parsing_status(line, &parser_data, map_data);
}
	
// have to pick up the keywords for each
// after all graphic data is parsed, parse the map
// parse_map(parser_data, map_data);
// allocate, free, reallocate ** space, copy the buffer
// before copying the buffer check if the string contains only the allowed character

// copy the map as a square 2d array
// check if the map is valid
