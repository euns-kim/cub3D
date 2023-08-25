/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:04:53 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/25 22:48:04 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// don't forget to free the line, when error exiting

void	parse_rgb(t_type type, char *line, t_parser_data *parser_data, t_map_data *map_data)
{
	
}

t_parser_exit_code	parse_texture(t_type type, char *line, t_parser_data *parser_data, t_map_data *map_data)
{
	t_parser_exit_code	exit_code;
	int					tmp_fd;

	exit_code = string_slicer_ws(line, parser_data);
	if (exit_code != PARSER_SUCCESS)
		return (exit_code);
	if (extension_check(parser_data->texture_path, ".png") == 0)
		return (BAD_TEXTURE_EXTENSION);
	tmp_fd = open(parser_data->texture_path, O_RDONLY);
	if (tmp_fd == -1)
		return (TEXTURE_OPEN_ERROR);
	close(tmp_fd);
	if (map_data->wall[type] != NULL)
		return (DATA_AMBIGUITY);
	map_data->wall[type] = mlx_load_png(parser_data->texture_path);
	if (map_data->wall[type] == NULL)
		return (TEXTURE_NOT_LOADED);
	if (map_data->wall[type]->width != map_data->wall[type]->height)
		return (BAD_TEXTURE_SIZE);
	return (PARSER_SUCCESS);
}

t_type	catch_type(char *line, int *idx)
{
	*idx = 0;
	while (line[*idx] && ft_strchr(WHITESPACES, line[*idx]) != 0)
		(*idx)++;
	if (line[(*idx)++] == 'N' && line[(*idx)++] == 'O')
		return (NORTH);
	else if (line[(*idx)++] == 'E' && line[(*idx)++] == 'A')
		return (EAST);	
	else if (line[(*idx)++] == 'S' && line[(*idx)++] == 'O')
		return (SOUTH);
	else if (line[(*idx)++] == 'W' && line[(*idx)++] == 'E')
		return (WEST);
	else if (line[(*idx)++] == 'F')
		return (FLOOR);
	else if (line[(*idx)++] == 'C')
		return (CEILING);
	else
		return (ERROR);
}
