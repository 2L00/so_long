/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 08:58:35 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/24 18:39:29 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_to_str(char *av, size_t hight_map, size_t len_map)
{
	size_t	i;
	char	*s;
	int		fd;
	char	**str;

	str = malloc(sizeof(char *) * (hight_map + 1));
	if (!str)
		return (NULL);
	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		exit((ft_printf("Error\n"), free(str), 1));
	s = get_next_line(fd);
	while (s && i < hight_map)
	{
		str[i] = malloc(sizeof(char) * (len_map + 1));
		if (!str[i])
			exit((ft_printf("Error\n"), freeing(s, str), 1));
		copy_map(s, str[i++]);
		free(s);
		s = get_next_line(fd);
	}
	str[i] = NULL;
	close(fd);
	return (str);
}
