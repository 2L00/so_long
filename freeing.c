/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:40:25 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/20 18:47:29 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freeing(char *s, char **str)
{
	int	i;

	i = 0;
	if (s)
		free(s);
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	str = NULL;
}

void	ft_free_fill(char **str, int i)
{
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
