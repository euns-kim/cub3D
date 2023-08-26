/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 21:05:16 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/26 18:07:02 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_exit_code	string_slicer_ws(char *line, t_parser_data *parser_data)
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
