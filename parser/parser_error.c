/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:06:31 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/23 17:39:58 by eunskim          ###   ########.fr       */
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
	else if (error == GRAPHIC_DATA_INCOMPLETE)
		ft_putstr_fd("Incomplete data.\n", 2);
	else if (error == NO_MAP_FOUND)
		ft_putstr_fd("No map is found.\n", 2);
	exit(error);
}

void	parser_free_before_exit(t_parser_data *parser_data, t_map_data *map_data)
{
	close(parser_data->map_fd);
}
