/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawang <sawang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 21:03:31 by sawang            #+#    #+#             */
/*   Updated: 2023/08/31 19:32:15 by sawang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "cub3D.h"

# ifndef STEP
#  define STEP 5
# endif

typedef struct s_input
{
	double	hori_delta;
	double	vert_delta;
	double	angle;
}				t_input;

void	update_hook_input(t_player player, t_input *input, keys_t key);
void	update_player(t_player *player, t_input *input, t_map_data map_data);

#endif
