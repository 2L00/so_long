/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abddahma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:24:01 by abddahma          #+#    #+#             */
/*   Updated: 2025/02/21 18:24:16 by abddahma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putstr(char *str);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr_hexa_upper(unsigned long n);
int	ft_putnbr_hexa_lower(unsigned long n);
int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_printf(const char *format, ...);
int	ft_pointer(void *ptr);

#endif
