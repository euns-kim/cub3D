/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:05:16 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/28 18:24:34 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int32_t	cub_color_atoi(char *start, int len)
{
	int32_t	sum;

	sum = 0;
	while (*start >= '0' && *start <= '9' && len)
	{
		sum = sum * 10 + (*start - '0');
		start++;
		len--;
	}
	return (sum);
}

t_parser_exit_code	get_rgb(t_type type, t_rgb *rgb_scanner, t_map_data *map_data)
{
	int32_t red;
	int32_t	green;
	int32_t	blue;
	int32_t color;

	red = cub_color_atoi(rgb_scanner->red_start, rgb_scanner->red_len);
	green = cub_color_atoi(rgb_scanner->green_start, rgb_scanner->green_len);
	blue = cub_color_atoi(rgb_scanner->blue_start, rgb_scanner->blue_len);
	printf("red: %d\n", red);
	printf("green: %d\n", green);
	printf("blue: %d\n", red);
	if (red > 255 || green > 255 || blue > 255)
		return (BAD_RGB);
	color = ((red << 24) | (green << 16) | (blue << 8) | 0xFF);
	printf("color: %x\n", color);
	if (type == FLOOR)
		map_data->floor_color = color;
	else if (type == CEILING)
		map_data->ceiling_color = color;
	return (PARSER_SUCCESS);
}

t_parser_exit_code	scan_color_code(char *line, int *idx, char *color_start, int *color_len)
{
	*color_len = 0;
	while (line[*idx] && ft_strchr(WHITESPACES, line[*idx]) != 0)
		(*idx)++;
	color_start = line + *idx;
	printf("%s\n", color_start);
	while (line[*idx] && line[*idx] != ',' && ft_strchr(WHITESPACES, line[*idx]) == 0)
	{
		if (ft_isdigit(line[*idx]) == 0)
			return (BAD_RGB);
		(*idx)++;
	}
	*color_len = line + *idx - color_start;
	printf("%d\n", *color_len);
	return (PARSER_SUCCESS);
}

t_parser_exit_code	texture_slicer(char *line, t_parser_data *parser_data)
{
	int i;
	int	start;
	int	end;

	i = 0;
	start = parser_data->scanner_idx;
	while (line[start] && ft_strchr(WHITESPACES, line[start]) != 0)
		start++;
	end = start;
	while (line[end] && ft_strchr(WHITESPACES, line[end]) == 0)
		end++;
	if (end - start < 4)
		return (GRAPHIC_DATA_INCOMPLETE);
	if (is_empty_line(line + end) == false)
		return (INVALID_DATA);
	free_p((void *) parser_data->texture_path);
	parser_data->texture_path = ft_calloc(1, end - start + 1);
	if (parser_data->texture_path == NULL)
		return (PARSER_MALLOC_ERROR);
	while (start + i < end - 1)
	{
		parser_data->texture_path[i] = line[start + i];
		i++;
	}
	printf("%s\n", parser_data->texture_path);
	return (PARSER_SUCCESS);
}

int	extension_check(const char *path, const char *extension)
{
	size_t	path_len;
	
	path_len = ft_strlen(path);
	if (path_len < 4)
		return (0);
	if (ft_strncmp(path + path_len - 4, extension, 4) == 0)
		return (1);
	return (0);
}
