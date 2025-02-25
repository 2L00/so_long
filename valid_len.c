/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:08:50 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/25 13:23:10 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	valid_len(char *av)
{
	int		fd;
	int		first_len;
	char	*s;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return ;
	s = get_next_line(fd);
	if (!s)
		exit((ft_printf("Error in the len\n"), close(fd), 1));
	first_len = len(s);
	while (s)
	{
		if (first_len != len(s))
		{
			while (s)
			{
				free(s);
				s = get_next_line(fd);
			}
			exit((ft_printf("Error in the len\n"), close(fd), 1));
		}
		free(s);
		s = get_next_line(fd);
	}
	close(fd);
}
