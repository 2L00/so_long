/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:03:01 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/21 17:12:06 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	freeall(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	wall_map(char **str, int hight_map, size_t len_map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[0][j] != '1' || str[i][0] != '1')
				exit((ft_printf("Error\n"), freeall(str), 1));
			if (str[i][len_map - 1] != '1')
				exit((ft_printf("Error\n"), freeall(str), 1));
			if (str[hight_map - 1][j] != '1')
				exit((ft_printf("Error\n"), freeall(str), 1));
			j++;
		}
		if (j != len_map)
			exit((ft_printf("Error\n"), freeall(str), 1));
		i++;
	}
}
