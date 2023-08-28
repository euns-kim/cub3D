/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:06:31 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/28 18:18:56 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	error_handler(t_parser_data *parser_data, \
		t_map_data *map_data, t_parser_exit_code error)
{
	ft_putstr_fd("Error\n", 2);
	parser_free_before_exit(parser_data, map_data);
	if (error == PARSER_MALLOC_ERROR)
		ft_putstr_fd("Malloc failed\n", 2);
	else if (error == EMPTY_FILE)
		ft_putstr_fd("Empty file.\n", 2);
	else if (error == INVALID_DATA)
		ft_putstr_fd("Invalid data contained.\n", 2);
	else if (error == BAD_TEXTURE_EXTENSION)
		ft_putstr_fd("Expected a .png file.\n", 2);
	else if (error == TEXTURE_OPEN_ERROR)
		ft_putstr_fd("Texture not readable.\n", 2);
	else if (error == BAD_TEXTURE_SIZE)
		ft_putstr_fd("Expected a 64x64 texture.\n", 2);
	else if (error == DATA_AMBIGUITY)
		ft_putstr_fd("Duplicated information.\n", 2);
	else if (error == TEXTURE_NOT_LOADED)
		ft_putstr_fd("Cannot load the texture.\n", 2);
	else if (error == GRAPHIC_DATA_INCOMPLETE)
		ft_putstr_fd("Incomplete data.\n", 2);
	else
		ft_putstr_fd("\n", 2);
	exit(error);
}

void	parser_free_before_exit(t_parser_data *parser_data, t_map_data *map_data)
{
	close(parser_data->map_fd);
	free_p(parser_data->texture_path);
	free_p(map_data->wall[NORTH]);
	free_p(map_data->wall[EAST]);
	free_p(map_data->wall[SOUTH]);
	free_p(map_data->wall[WEST]);
}
