/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:50:11 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/22 22:08:47 by rvegas-j         ###   ########.fr       */
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
	ft_printf_i1(flags, j, i);
	
}

void	ft_printf_i1(t_flags *flags, int j, int i)
{
	if (flags->widthbool == 0 && flags->precibool == 0)
	{
		if (flags->minusint == 1)
			write(1, "-", 1) && flags->bytes++;
		ft_putnbr_fd(j, flags, 1);
	}
	if (flags->widthbool == 1 && flags->precibool == 0)
	{
		if (flags->zero == 0)
		{
			i = flags->width - flags->length - flags->minusint;
			if (flags->minus == 0)
			{
				ft_putblank(i, flags);
				if (flags->minusint == 1)
				{
					write(1, "-", 1);
					flags->bytes++;
				}
				ft_putnbr_fd(j, flags, 1);
			}
			if (flags->minus == 1)
			{
				if (flags->minusint == 1)
				{
					write(1, "-", 1);
					flags->bytes++;
				}
				ft_putnbr_fd(j, flags, 1);
				ft_putblank(i, flags);
			}
		}
		if (flags->zero == 1)
		{
			i = flags->width - flags->length - flags->minusint;
			if (flags->minusint == 1)
				ft_writeandbyte(flags);
			ft_putzero(i, flags);
			ft_putnbr_fd(j, flags, 1);
		}
	}
	if (flags->widthbool == 0 && flags->precibool == 1)
	{
		i = flags->preci - flags->length;
		if (flags->minusint == 1)
			ft_writeandbyte(flags);
		ft_putzero(i, flags);
		ft_putnbr_fd(j, flags, 1);
	}
	if (flags->widthbool == 1 && flags->precibool == 1)
	{
		if (flags->width < flags->preci)
			flags->width = flags->preci;
		if (flags->width >= flags->preci)
		{
			if (flags->preci < flags->length)
				flags->preci = flags->length;
			i = flags->width - flags->preci - flags->minusint;
			ft_putblank(i, flags);
			i = flags->preci - flags->length;
			if (flags->minusint == 1)
				ft_writeandbyte(flags);
			ft_putzero(i, flags);
			ft_putnbr_fd(j, flags, 1);
		}
	}
}

void	ft_writeandbyte(t_flags *flags)
{
	write(1, "-", 1);
	flags->bytes++;
}

	/*printf("\npreci:%i", flags->preci);
	printf("\nlength:%i", flags->length);
	printf("\nminusint:%i", flags->minusint);
	printf("\nValor de i:%i", i);*/