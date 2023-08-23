/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:08:20 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/23 18:45:23 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_strchr(WHITESPACES, line[i]) != 0)
		i++;
	if (line[i] != '\0')
		return (false);
	return (true);
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
	parser_data->scanner_idx = 0;
	parser_data->graphic_data_parsed = false;
	parser_data->player_cnt = 0;
	parser_data->tmp_map = NULL;
	
}
