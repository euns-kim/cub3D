/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunskim <eunskim@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 18:59:42 by eunskim           #+#    #+#             */
/*   Updated: 2023/08/22 18:59:53 by eunskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	extension_check(const char *path, const char *extension)
{
	size_t	path_len;
	
	path_len = ft_strlen(path);
	if (path_len < 4)
		return (0);
	if (ft_strncmp(path - path_len + 4, extension, 4) == 0)
		return (1);
	return (0);
}
