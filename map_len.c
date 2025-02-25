/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 11:18:15 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/21 17:09:27 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	map_len(char *av)
{
	size_t	i;
	char	*s;
	int		fd;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		exit((ft_printf("Error\n"), 1));
	s = get_next_line(fd);
	if (!s)
		exit((ft_printf("Error\n"), 1));
	while (s[i] && s[i] != '\n' && s[i] != '\0')
		i++;
	while (s)
	{
		free(s);
		s = get_next_line(fd);
	}
	free(s);
	close(fd);
	return (i);
}
