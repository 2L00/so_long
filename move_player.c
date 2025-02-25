/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:55:49 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/21 18:02:12 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	right(t_MAP *map, int y, int x)
{
	if (map->str[y][x - 1] == 'E')
	{
		write(1, "\r", 1);
		ft_putstr_fd("The Player Moves: ", 0);
		ft_putnbr_fd(map->move++, 0);
		map->str[y][x] = '0';
		x--;
		map->p_x = x;
		map->str[y][map->p_x] = 'P';
		place_element(map);
	}
	else if (map->str[y][x - 1] != '1')
	{
		write(1, "\r", 1);
		ft_putstr_fd("The Player Moves: ", 0);
		ft_putnbr_fd(map->move++, 0);
		map->str[y][x] = '0';
		x--;
		map->p_x = x;
		map->str[y][x] = 'P';
		map->str[map->e_y][map->e_x] = 'E';
		place_element(map);
	}
}

static void	up(t_MAP *map, int y, int x)
{
	if (map->str[y - 1][x] == 'E')
	{
		write(1, "\r", 1);
		ft_putstr_fd("The Player Moves: ", 0);
		ft_putnbr_fd(map->move++, 0);
		map->str[y][x] = '0';
		y--;
		map->p_y = y;
		map->str[map->p_y][x] = 'P';
		place_element(map);
	}
	else if (map->str[y - 1][x] != '1')
	{
		write(1, "\r", 1);
		ft_putstr_fd("The Player Moves: ", 0);
		ft_putnbr_fd(map->move++, 0);
		map->str[y][x] = '0';
		y--;
		map->p_y = y;
		map->str[map->p_y][x] = 'P';
		map->str[map->e_y][map->e_x] = 'E';
		place_element(map);
	}
}

static void	down(t_MAP *map, int y, int x)
{
	if (map->str[y + 1][x] == 'E')
	{
		write(1, "\r", 1);
		ft_putstr_fd("The Player Moves: ", 0);
		ft_putnbr_fd(map->move++, 0);
		map->str[y][x] = '0';
		y++;
		map->p_y = y;
		map->str[map->p_y][x] = 'P';
		place_element(map);
	}
	else if (map->str[y + 1][x] != '1')
	{
		write(1, "\r", 1);
		ft_putstr_fd("The Player Moves: ", 0);
		ft_putnbr_fd(map->move++, 0);
		map->str[y][x] = '0';
		y++;
		map->p_y = y;
		map->str[map->p_y][x] = 'P';
		map->str[map->e_y][map->e_x] = 'E';
		place_element(map);
	}
}

static void	lift(t_MAP *map, int y, int x)
{
	if (map->str[y][x + 1] == 'E')
	{
		write(1, "\r", 1);
		ft_putstr_fd("The Player Moves: ", 0);
		ft_putnbr_fd(map->move++, 0);
		map->str[y][x] = '0';
		x++;
		map->p_x = x;
		map->str[y][map->p_x] = 'P';
		place_element(map);
	}
	else if (map->str[y][x + 1] != '1')
	{
		write(1, "\r", 1);
		ft_putstr_fd("The Player Moves: ", 0);
		ft_putnbr_fd(map->move++, 0);
		map->str[y][x] = '0';
		x++;
		map->p_x = x;
		map->str[y][map->p_x] = 'P';
		map->str[map->e_y][map->e_x] = 'E';
		place_element(map);
	}
}

void	move_player(int key, t_MAP *map)
{
	int (x), y;
	x = map->p_x;
	y = map->p_y;
	if (out(map, y, x, key) == 1 && no_collectebel(map) == 0)
		exit_hook(map);
	if (key == 65361)
		right(map, y, x);
	if (key == 65362)
		up(map, y, x);
	if (key == 65364)
		down(map, y, x);
	if (key == 65363)
		lift(map, y, x);
}
