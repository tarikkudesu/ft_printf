/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:29:02 by tamehri           #+#    #+#             */
/*   Updated: 2023/11/20 09:35:06 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putadd(unsigned long add, int *index)
{
	char	*base;

	base = "0123456789abcdef";
	if (add < 16)
		ft_putchar(*(base + add), index);
	else
	{
		ft_putadd(add / 16, index);
		ft_putadd(add % 16, index);
	}
}

void	ft_flag(va_list list, const char format, int *index)
{
	if (format == 'c')
		ft_putchar((char)va_arg(list, int), index);
	else if (format == 's')
		ft_putstr(va_arg(list, char *), index);
	else if (format == 'p')
	{
		ft_putstr("0x", index);
		ft_putadd(va_arg(list, unsigned long), index);
	}
	else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(list, int), index);
	else if (format == 'u')
		ft_putnbr_u(va_arg(list, unsigned int), index);
	else if (format == 'x')
		ft_putnbr_hex(va_arg(list, unsigned int), format, index);
	else if (format == 'X')
		ft_putnbr_hex(va_arg(list, unsigned int), format, index);
	else
		ft_putchar(format, index);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		index;

	if (write(1, "", 0) == -1)
		return (-1);
	index = 0;
	va_start(list, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_flag(list, *format, &index);
		}
		else
			ft_putchar(*format, &index);
		if (!*format)
			break ;
		format++;
	}
	va_end(list);
	return (index);
}
