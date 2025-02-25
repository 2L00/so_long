/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:56:50 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/23 18:01:57 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	info_map(char **av)
{
	char	**str;
	char	*ber;

	int (i), j = 0;
	i = 0;
	ber = ".ber";
	while (av[1][i] != '.')
		i++;
	if (av[1][i - 1] == '/')
		exit((ft_printf("Error\n"), 1));
	while (av[1][i])
	{
		if (av[1][i] != ber[j])
			exit((ft_printf("Error\n"), 1));
		i++;
		j++;
	}
	str = map_to_str(av[1], map_hight(av[1]), map_len(av[1]));
	wall_map(str, map_hight(av[1]), map_len(av[1]));
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
