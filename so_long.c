/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:44:52 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/24 18:30:32 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_MAP	*map;
	char	**str;
	char	**copy;

	if (ac != 2)
		exit((ft_printf("Error\n"), 1));
	valid_len(av[1]);
	info_map(av);
	other_info(av[1]);
	map = malloc(sizeof(t_MAP));
	if (!map)
		return (1);
	advance_info(av[1], map);
	str = map_to_str(av[1], map_hight(av[1]), map_len(av[1]));
	copy = str;
	flood_fill(av[1], copy, map);
	map->move = 0;
	ft_mlx(str, map);
	return (0);
}
