/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advance_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:33:12 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/21 17:06:57 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	if_exist(char c, t_MAP *map)
{
	if (c == '0')
		map->space += 1;
	if (c == '1')
		map->wall += 1;
	if (c == 'C')
		map->collectible += 1;
	if (c == 'P')
		map->player += 1;
	if (c == 'E')
		map->exit += 1;
}

static void	is_all_exist(t_MAP *map)
{
	if (map->player != 1)
		exit((ft_printf("Error\n"), free(map), 1));
	if (map->exit != 1)
		exit((ft_printf("Error\n"), free(map), 1));
	if (map->collectible == 0)
		exit((ft_printf("Error\n"), free(map), 1));
}

static void	initial_map(t_MAP *map)
{
	map->space = 0;
	map->wall = 0;
	map->collectible = 0;
	map->exit = 0;
	map->player = 0;
}

void	advance_info(char *av, t_MAP *map)
{
	char	*s;

	int (fd), i = 0;
	fd = open(av, O_RDONLY);
	s = get_next_line(fd);
	initial_map(map);
	while (s)
	{
		i = 0;
		while (s[i] != '\n' && s[i] != '\0')
		{
			if_exist(s[i], map);
			i++;
		}
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	is_all_exist(map);
}
