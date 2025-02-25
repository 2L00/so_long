/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:21:44 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/21 17:10:14 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	other_info(char *av)
{
	char	*s;

	int (fd), i = 0;
	fd = open(av, O_RDONLY);
	s = get_next_line(fd);
	while (s)
	{
		i = 0;
		while (s[i] != '\n' && s[i] != '\0')
		{
			if (s[i] != '1' && s[i] != '0' && s[i] != 'P' && s[i] != 'E'
				&& s[i] != 'C')
			{
				while (s)
				{
					free(s);
					s = get_next_line(fd);
				}
				exit((ft_printf("Error\n"), close(fd), 1));
			}
			i++;
		}
		free(s);
		s = get_next_line(fd);
	}
}
