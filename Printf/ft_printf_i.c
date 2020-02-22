/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:50:11 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/22 17:50:03 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_i(t_flags *flags)
{
	int i;
	int j;

	i = 0;
	if (!(j = (va_arg(flags->valist, int))))
		j = 0;
	flags->length = ft_numofdigits(j);
	if (flags->preci > flags->length)
		flags->zero = 1;
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
	if (flags->minus == 0 && flags->zero == 0)
		ft_printf_i1(flags, j, i);
	if (flags->minus == 0 && flags->zero == 1)
		ft_printf_i1(flags, j, i);
}

void	ft_printf_i1(t_flags *flags, int j, int i)
{
	if (flags->preci < 0)
		flags->preci = (flags->preci * -1);
	if (flags->widthbool == 0 && flags->precibool == 0)
		ft_putnbr_fd(j, flags, 1);
	if (flags->widthbool == 1 && flags->precibool == 1)
	{
		if (flags->preci > flags->width)
			flags->width = flags->preci;
		i = flags->width - flags->length;
		if (flags->zero == 1)
			ft_putzero(i, flags);
		else
			ft_putblank(i, flags);
		ft_putnbr_fd(j, flags, 1);
	}
	if (flags->widthbool == 1 && flags->precibool == 0)
	{
		i = flags->width - flags->length;
		if (flags->zero == 1)
			ft_putzero(i, flags);
		else
			ft_putblank(i, flags);
		ft_putnbr_fd(j, flags, 1);
	}
}
