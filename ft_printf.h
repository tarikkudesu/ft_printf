/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamehri <tamehri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:19:27 by tamehri           #+#    #+#             */
/*   Updated: 2023/11/18 22:45:48 by tamehri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(const char c, int *index);
void	ft_putstr(const char *s, int *index);
void	ft_putadd(unsigned long add, int *index);
void	ft_putnbr(int nbr, int *index);
void	ft_putnbr_u(unsigned int n, int *index);
void	ft_putnbr_hex(unsigned int n, char c, int *index);

#endif
