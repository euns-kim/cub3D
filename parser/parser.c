/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:57:35 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/18 22:51:11 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_exit_code	parser(t_map_data *map_data, char *filename)
{
	t_parser_data		parser_data;

	init_parse_data(parser_data); // initiate data structure
	open_map_file(filename, &parser_data.map_fd); // check extension and open file
	// should have a loop of get_next_line here?
	parse_graphic_data(parser_data, map_data);
	// have to pick up the keywords for each
	// after all graphic data is parsed, parse the map
	parse_map(parser_data, map_data);
	// allocate, free, reallocate ** space, copy the buffer
	// before copying the buffer check if the string contains only the allowed character
	
	// copy the map as a square 2d array
	// check if the map is valid
}