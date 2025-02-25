/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 14:59:30 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/21 17:08:08 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill(t_MAP *map, char **str, int x, int y)
{
	if (str[y][x] == '1')
		return ;
	str[y][x] = '1';
	fill(map, str, x + 1, y);
	fill(map, str, x - 1, y);
	fill(map, str, x, y + 1);
	fill(map, str, x, y - 1);
}

static void	flood(char **str, char **copy, t_MAP *map)
{
	int (j), i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'C' || copy[i][j] == 'E')
			{
				ft_free_fill(copy, 0);
				exit((ft_printf("Error\n"), free(map), ft_free_fill(str, 0),
						1));
			}
			j++;
		}
		i++;
	}
}

static char	**ss(char **copy, int *x, int *y, t_MAP *map)
{
	char	**str;

	int (j), i = 0;
	str = malloc(sizeof(char *) * (map->hight_map + 1));
	if (!str)
		exit((ft_printf("Error\n"), free(map), ft_free_fill(copy, 0), 1));
	while (copy[i])
	{
		j = 0;
		str[i] = ft_strdup(copy[i]);
		if (!str[i])
			exit((ft_printf("Error\n"), free(map), ft_free_fill(str, 0),
					ft_free_fill(copy, 0), 1));
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				*x = j;
				*y = i;
			}
			j++;
		}
		i++;
	}
	return (str[i] = NULL, str);
}

void	flood_fill(char *av, char **copy, t_MAP *map)
{
	char	**str;

	int (x), y = -1;
	x = -1;
	map->hight_map = map_hight(av);
	map->len_map = map_len(av);
	str = ss(copy, &x, &y, map);
	if (x != -1 && y != -1)
		fill(map, str, x, y);
	flood(copy, str, map);
	ft_free_fill(str, 0);
}
