/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 16:43:06 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/23 00:20:11 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, t_flags *flags, int fd)
{
	if (n == -2147483648)
		ft_putstr_a("-2147483648", flags);
	else if (n < 0)
	{
		ft_putchar_fd('-', flags, fd);
		ft_putnbr_fd(-n, flags, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, flags, fd);
		ft_putchar_fd(n % 10 + '0', flags, fd);
	}
	else
		ft_putchar_fd(n + '0', flags, fd);
}

void	ft_putnbr_fd_ui(unsigned int n, t_flags *flags, int fd)
{
	if (n == 4294967295)
		ft_putstr_a("4294967295", flags);
	else if (n < 0)
	{
		ft_putchar_fd('-', flags, fd);
		ft_putnbr_fd(-n, flags, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, flags, fd);
		ft_putchar_fd(n % 10 + '0', flags, fd);
	}
	else
		ft_putchar_fd(n + '0', flags, fd);
}

void	ft_putchar_fd(char c, t_flags *flags, int fd)
{
	write(fd, &c, 1);
	flags->bytes++;
}
