/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:03:31 by sawang            #+#    #+#             */
/*   Updated: 2023/08/22 21:03:31 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "cub3d.h"

typedef struct s_input
{
	int		horizontal_move; //move the player left or right using keys A and D
	int		vertical_move; //move the player forward or backward using keys W and S
	double	rotated; //rotated direction of the player using the arrow keys
}				t_input;

void	update_player_info(t_player *player, t_input *input);

#endif
