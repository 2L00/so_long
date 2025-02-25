/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:21:40 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/21 18:41:52 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_element(t_MAP *map)
{
	int (x), y = 0;
	while (map->str[y])
	{
		x = 0;
		while (map->str[y][x])
		{
			if (map->str[y][x] == '1')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->img_wall, x * 64, y * 64);
			else if (map->str[y][x] == 'E')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->img_door, x * 64, y * 64);
			else if (map->str[y][x] == 'C')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->img_coin, x * 64, y * 64);
			else if (map->str[y][x] == '0')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->img_space, x * 64, y * 64);
			else if (map->str[y][x] == 'P')
				mlx_put_image_to_window(map->mlx_ptr, map->win_ptr,
					map->img_player, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

static void	find_player(char **str, t_MAP *map)
{
	int (x), y = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			if (str[y][x] == 'P')
			{
				map->p_x = x;
				map->p_y = y;
			}
			if (str[y][x] == 'E')
			{
				map->e_x = x;
				map->e_y = y;
			}
			x++;
		}
		y++;
	}
}

static void	not_exist(char **str, t_MAP *map)
{
	if (!map->mlx_ptr || !map->img_wall || !map->img_door || !map->img_player
		|| !map->img_coin || !map->img_space)
	{
		if (map->img_wall)
			mlx_destroy_image(map->mlx_ptr, map->img_wall);
		if (map->img_door)
			mlx_destroy_image(map->mlx_ptr, map->img_door);
		if (map->img_player)
			mlx_destroy_image(map->mlx_ptr, map->img_player);
		if (map->img_coin)
			mlx_destroy_image(map->mlx_ptr, map->img_coin);
		if (map->img_space)
			mlx_destroy_image(map->mlx_ptr, map->img_space);
		if (map->win_ptr)
			mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		if (map->mlx_ptr)
			mlx_destroy_display(map->mlx_ptr);
		exit((ft_printf("Error\n"), ft_free_fill(str, 0), free(map->mlx_ptr),
				free(map), 1));
	}
	find_player(str, map);
	place_element(map);
}

static int	key_hook(int keycode, t_MAP *map)
{
	if (keycode == 65307)
		exit_hook(map);
	move_player(keycode, map);
	return (0);
}

void	ft_mlx(char **str, t_MAP *map)
{
	int (x), y = 0;
	map->mlx_ptr = mlx_init();
	if (!map->mlx_ptr)
		exit((ft_free_fill(str, 0), free(map), 1));
	map->win_ptr = mlx_new_window(map->mlx_ptr, map->len_map * 64,
			map->hight_map * 64, "So_Long");
	if (!map->win_ptr)
		not_exist(str, map);
	map->str = str;
	x = 0;
	map->img_wall = mlx_xpm_file_to_image(map->mlx_ptr, "textures/1.xpm", &x,
			&y);
	map->img_door = mlx_xpm_file_to_image(map->mlx_ptr, "textures/E.xpm", &x,
			&y);
	map->img_player = mlx_xpm_file_to_image(map->mlx_ptr, "textures/P.xpm", &x,
			&y);
	map->img_coin = mlx_xpm_file_to_image(map->mlx_ptr, "textures/C.xpm", &x,
			&y);
	map->img_space = mlx_xpm_file_to_image(map->mlx_ptr, "textures/0.xpm", &x,
			&y);
	not_exist(str, map);
	mlx_hook(map->win_ptr, 2, 1L << 0, key_hook, map);
	mlx_hook(map->win_ptr, 17, 1L << 0, exit_hook, map);
	mlx_loop(map->mlx_ptr);
}
