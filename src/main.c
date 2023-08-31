/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 20:24:45 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/31 19:16:14 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "cub3D.h"
#include "raycast.h"

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

void	init_data(t_cub *data)
{
	init_map_size(&(data->map_size));
	get_initial_player_info(data->map_data, data->map_size.tile_size, \
		&(data->player));
	init_input(&(data->hook_input));
}

int	main(int argc, char **argv)
{
	t_cub				data;
	t_render_exit_code	render_exit_code;

	arg_check(argc, argv);
	parser(&data.map_data, argv[1]);
	init_data(&data);
	render_exit_code = start_render(&data);
	quit(&data, render_exit_code);
}
