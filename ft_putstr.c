/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:19:31 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/21 18:25:34 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr(char *str)
{
	int	x;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	x = ft_strlen(str);
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	return (x);
}
