/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:22:29 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/23 18:54:03 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// don't forget to free the line, when error exiting

void	parse_rgb(t_type type, char *line, t_parser_data parser_data, t_map_data map_data)
{
	
}

void	parse_texture(t_type type, char *line, t_parser_data parser_data, t_map_data map_data)
{
	
}

t_type	catch_type(char *line, int *scanner_idx)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
}