/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:08:20 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/22 21:08:22 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	open_map_file(const char *path, int map_fd)
{
	map_fd = open(path, O_RDONLY); 
	if (map_fd == -1)
	{
		ft_putstr_fd("Error\nFailed to open a file.\n", 2);
		exit(OPEN_ERROR);
	}
}

void	init_data(t_map_data *map_data, t_parser_data *parser_data)
{
	map_data->wall[NORTH] = NULL;
	map_data->wall[EAST] = NULL;
	map_data->wall[SOUTH] = NULL;
	map_data->wall[WEST] = NULL;
	map_data->floor_color = -1;
	map_data->ceiling_color = -1;
	map_data->map_width = 0;
	map_data->map_height = 0;
	map_data->map = NULL;
	parser_data->map_fd = 0;
	parser_data->graphic_data_parsed = false;
	parser_data->tmp_map = NULL;
	
}