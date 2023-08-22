/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:06:31 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/22 22:34:35 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	error_handler(t_parser_data *parser_data, \
		t_map_data *map_data, t_parser_exit_code error)
{
	ft_putstr_fd("Error\n", 2);
	free_before_exit(parser_data, map_data);
	if (error == EMPTY_FILE)
		ft_putstr_fd("Empty file.\n", 2);
	exit(error);
}

void	free_before_exit(t_parser_data *parser_data, t_map_data *map_data)
{
	close(parser_data->map_fd);
}
