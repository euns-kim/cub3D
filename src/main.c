/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:24:45 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/31 14:47:39 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	check_leaks(void)
{
	system("leaks cub3D");
}

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
		ft_putstr_fd("Error\nExpected a .cub file.\n", 2);
		exit(CUB_WRONG_EXTENSION);
	}
}

int	main(int argc, char **argv)
{
	t_cub	data;

	atexit(check_leaks);
	arg_check(argc, argv);
	parser(&data.map_data, argv[1]);
	return (0);
}
