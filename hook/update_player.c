/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:42:38 by sawang            #+#    #+#             */
/*   Updated: 2023/08/22 21:42:38 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "hook.h"

void	update_player_info(t_player *player, t_input *input)
{
	player->pos_modif.x = player->pos.x + input->horizontal_move;
	player->pos_modif.y = player->pos.y + input->vertical_move;
	player->dir_modif = player->dir + input->rotated;
}
