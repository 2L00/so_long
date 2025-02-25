/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_collectebel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:36:28 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/20 09:29:39 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	no_collectebel(t_MAP *map)
{
	int (x), y = 0;
	while (map->str[y])
	{
		x = 0;
		while (map->str[y][x])
		{
			if (map->str[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	out(t_MAP *map, int y, int x, int key)
{
	if (x - 1 == map->e_x && y == map->e_y)
		if (key == 65361)
			return (1);
	if (x == map->e_x && y - 1 == map->e_y)
		if (key == 65362)
			return (1);
	if (x + 1 == map->e_x && y == map->e_y)
		if (key == 65363)
			return (1);
	if (x == map->e_x && y + 1 == map->e_y)
		if (key == 65364)
			return (1);
	return (0);
}
