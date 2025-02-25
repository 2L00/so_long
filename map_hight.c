/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_hight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 19:07:51 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/21 17:09:08 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	map_hight(char *av)
{
	size_t	i;
	char	*s;
	int		fd;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (0);
	s = get_next_line(fd);
	if (!s)
		exit((ft_printf("Error\n"), 1));
	while (s)
	{
		i++;
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
	return (i);
}
