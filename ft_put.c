/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:30:54 by tamehri           #+#    #+#             */
/*   Updated: 2023/11/18 22:40:27 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_hex(unsigned int n, char c, int *index)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n < 16)
		ft_putchar(*(base + n), index);
	else
	{
		ft_putnbr_hex(n / 16, c, index);
		ft_putchar(base[n % 16], index);
	}
}

void	ft_putnbr_u(unsigned int n, int *index)
{
	if (n < 10)
		ft_putchar("0123456789"[n], index);
	else
	{
		ft_putnbr_u(n / 10, index);
		ft_putchar("0123456789"[n % 10], index);
	}
}

void	ft_putnbr(int nbr, int *index)
{
	long	n;

	n = nbr;
	if (n < 0)
	{
		ft_putchar('-', index);
		n *= -1;
	}
	if (n < 10)
		ft_putchar("0123456789"[n], index);
	else
	{
		ft_putnbr(n / 10, index);
		ft_putchar("0123456789"[n % 10], index);
	}
}

void	ft_putstr(const char *s, int *index)
{
	if (s == NULL)
		ft_putstr("(null)", index);
	else
		while (*s)
			ft_putchar(*s++, index);
}

void	ft_putchar(const char c, int *index)
{
	write(1, &c, 1);
	(*index)++;
}
