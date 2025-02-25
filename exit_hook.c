/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:02:59 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/20 10:03:27 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_hook(t_MAP *map)
{
	mlx_destroy_image(map->mlx_ptr, map->img_wall);
	mlx_destroy_image(map->mlx_ptr, map->img_door);
	mlx_destroy_image(map->mlx_ptr, map->img_player);
	mlx_destroy_image(map->mlx_ptr, map->img_coin);
	mlx_destroy_image(map->mlx_ptr, map->img_space);
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	mlx_destroy_display(map->mlx_ptr);
	free(map->mlx_ptr);
	ft_free_fill(map->str, 0);
	free(map);
	exit(0);
}
