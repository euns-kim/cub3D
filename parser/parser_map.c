/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:15:48 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/29 21:16:40 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_exit_code parse_tmp_map(char *line, t_parser_data *parser_data, t_map_data *map_data)
{
	t_parser_exit_code	exit_code;

	while (line)
	{
		if (is_empty_line(line) == true)
			break ;
		exit_code = line_check(line, parser_data);
		if (exit_code != PARSER_SUCCESS)
			return (free(line), exit_code);
		parser_data->tmp_map = extend_string_array(parser_data->tmp_map, map_data->height);
		if (parser_data->tmp_map == NULL)
			return (free(line), PARSER_MALLOC_ERROR);
		parser_data->tmp_map[map_data->height] = cub_strdup(line);
		if (parser_data->tmp_map[map_data->height] == NULL)
			return (free(line), PARSER_MALLOC_ERROR);
		map_data->height++;
		free(line);
		line = get_next_line(parser_data->map_fd);
	}
	return (check_map_parsing_status(line, parser_data));
}

void	parse_map(char *line, t_parser_data *parser_data, t_map_data *map_data)
{
	t_parser_exit_code	exit_code;

	exit_code = parse_tmp_map(line, parser_data, map_data);
	if (exit_code != PARSER_SUCCESS)
		error_handler(parser_data, map_data, exit_code);
	printf("map height: %d\n", map_data->height);
	for (int i = 0; parser_data->tmp_map[i] != NULL; i++)
	{
		// printf("#%d: ", i);
		printf("%s\n", parser_data->tmp_map[i]);	
	}
}