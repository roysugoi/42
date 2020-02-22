/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:50:11 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/23 00:21:16 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_u(t_flags *flags)
{
	int				i;
	unsigned int	j;

	i = 0;
	if (!(j = (va_arg(flags->valist, unsigned int))))
		j = 0;
	if (j < 0)
	{
		j = j * -1;
		flags->minusint = 1;
	}
	flags->length = ft_numofdigits(j);
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
	if (flags->preci == 1)
		flags->zero = 0;
	ft_printf_u1(flags, j, i);
}

void	ft_printf_u1(t_flags *flags, unsigned int j, int i)
{
	if (flags->widthbool == 0 && flags->precibool == 0)
	{
		if (flags->minusint == 1)
			ft_writeandbyte(flags);
		ft_putnbr_fd_ui(j, flags, 1);
	}
	ft_printf_u2(flags, j, i);
}

void	ft_printf_u2(t_flags *flags, unsigned int j, int i)
{
	if (flags->widthbool == 1 && flags->precibool == 0)
	{
		if (flags->zero == 0)
		{
			i = flags->width - flags->length - flags->minusint;
			if (flags->minus == 0)
			{
				ft_putblank(i, flags);
				if (flags->minusint == 1)
					ft_writeandbyte(flags);
				ft_putnbr_fd_ui(j, flags, 1);
			}
			if (flags->minus == 1)
			{
				if (flags->minusint == 1)
					ft_writeandbyte(flags);
				ft_putnbr_fd_ui(j, flags, 1);
				ft_putblank(i, flags);
			}
		}
	}
	ft_printf_u3(flags, j, i);
}

void	ft_printf_u3(t_flags *flags, unsigned int j, int i)
{
	if (flags->widthbool == 1 && flags->precibool == 0)
	{
		if (flags->zero == 1)
		{
			i = flags->width - flags->length - flags->minusint;
			if (flags->minusint == 1)
				ft_writeandbyte(flags);
			ft_putzero(i, flags);
			ft_putnbr_fd_ui(j, flags, 1);
		}
	}
	ft_printf_u4(flags, j, i);
}

void	ft_printf_u4(t_flags *flags, unsigned int j, int i)
{
	if (flags->widthbool == 0 && flags->precibool == 1)
	{
		i = flags->preci - flags->length;
		if (flags->minusint == 1)
			ft_writeandbyte(flags);
		if (flags->preci != 0)
		{
			ft_putzero(i, flags);
			ft_putnbr_fd_ui(j, flags, 1);
		}
	}
	ft_printf_u5(flags, j, i);
}
