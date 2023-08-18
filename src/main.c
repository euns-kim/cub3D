/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:24:45 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/18 22:50:38 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_cub	data;

	if (argc != 2)
	{
		ft_putstr_fd("Invalid argument.", 2); // errors better handled separately
		ft_putstr_fd("Usage: ./cub3D [filename].cub\n", 2);
		return (1);
	}
	parser(&data.map_data, argv[1]); // error exit at each time
	return (0);
}