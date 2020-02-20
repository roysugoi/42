/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:08:00 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/20 22:44:49 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_c(t_flags *flags)
{
	int		i;
	int		t;

	i = 0;
	t = va_arg(flags->valist, int);
	flags->length = 1;
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
	if (flags->minus == 0 && flags->zero == 0)
		ft_printf_c1(flags, t, i);
	if (flags->minus == 1 && flags->zero == 0)
		ft_printf_c2(flags, t, i);
	if (flags->minus == 0 && flags->zero == 1)
		ft_printf_c1(flags, t, i);
}

void	ft_printf_c1(t_flags *flags, int s, int i)
{
	if (flags->preci < 0)
		flags->preci = (flags->preci * -1);
	if (flags->preci > flags->length)
		flags->preci = flags->length;
	if (flags->widthbool == 1 && flags->precibool == 1)
	{
		if (flags->preci > flags->length)
			flags->preci = flags->length;
		i = flags->width - flags->preci;
		ft_putblank(i, flags);
		write(1, &s, 1) && flags->bytes++;
	}
	if (flags->widthbool == 0 && flags->precibool == 1)
		write(1, &s, 1) && flags->bytes++;
	if (flags->widthbool == 1 && flags->precibool == 0)
	{
		i = flags->width - flags->length;
		if (flags->zero == 1)
			ft_putzero(i, flags);
		else
			ft_putblank(i, flags);
		write(1, &s, 1) && flags->bytes++;
	}
	if (flags->widthbool == 0 && flags->precibool == 0)
		write(1, &s, 1) && flags->bytes++;
}

void	ft_printf_c2(t_flags *flags, int s, int i)
{
	if (flags->widthbool == 1 && flags->precibool == 1)
	{
		if (flags->preci > flags->length)
			flags->preci = flags->length;
		i = flags->width - flags->preci;
		write(1, &s, 1);
		flags->bytes++;
		ft_putblank(i, flags);
	}
	if (flags->widthbool == 0 && flags->precibool == 1)
	{
		if (flags->preci > flags->length)
			flags->preci = flags->length;
		write(1, &s, 1) && flags->bytes++;
	}
	if (flags->widthbool == 1 && flags->precibool == 0)
	{
		i = flags->width - flags->length;
		write(1, &s, 1) && flags->bytes++;
		ft_putblank(i, flags);
	}
	if (flags->widthbool == 0 && flags->precibool == 0)
		write(1, &s, 1) && flags->bytes++;
}
