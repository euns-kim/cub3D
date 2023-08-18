/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:24:45 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/18 20:32:50 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_cub	data;
	if (argc != 2)
	{
		ft_putstr_fd("Invalid argument.", 2); // errors better handled separately
		ft_putstr_fd("Usage: ./cub3D [filename].cub", 2);
		return (1);
	}
	data.map_data = ft_calloc(1, sizeof(t_map_data));
	if (data.map_data == NULL)
	{
		ft_putstr_fd("Malloc failed\n.", 2);
		return (1);
	}
	parser(data.map_data);
	return (0);
}