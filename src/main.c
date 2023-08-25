/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:24:45 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/25 21:05:41 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	arg_check(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid argument.\n", 2);
		ft_putstr_fd("Usage: ./cub3D [filename].cub\n", 2);
		exit(CUB_INVALID_ARGUMENT);
	}
	if (extension_check(argv[1], ".cub") == 0)
	{
		ft_putstr_fd("Error\nWrong file extension. Expected a .cub file.\n", 2);
		exit(CUB_WRONG_EXTENSION);
	}
}

int	main(int argc, char **argv)
{
	t_cub	data;

	arg_check(argc, argv);
	parser(&data.map_data, argv[1]);
	return (0);
}
