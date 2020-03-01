/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:06:59 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/26 19:02:09 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_u5(t_flags *flags, unsigned int j, int i)
{
	if (flags->widthbool == 1 && flags->precibool == 1)
	{
		if (flags->minus == 0)
		{
			if (flags->width < flags->preci)
				flags->width = flags->preci;
			if (flags->width >= flags->preci)
			{
				if (flags->preci != 0)
					if (flags->preci < flags->length)
						flags->preci = flags->length;
				i = flags->width - flags->preci - flags->minusint;
				ft_putblank(i, flags);
				i = flags->preci - flags->length;
				if (flags->minusint == 1)
					ft_writeandbyte(flags);
				ft_putzero(i, flags);
				if (flags->preci != 0)
					ft_putnbr_fd(j, flags, 1);
			}
		}
	}
	ft_printf_u6(flags, j, i);
}

void	ft_printf_u6(t_flags *flags, unsigned int j, int i)
{
	if (flags->widthbool == 1 && flags->precibool == 1)
	{
		if (flags->minus == 1)
		{
			if (flags->width < flags->preci)
				flags->width = flags->preci;
			if (flags->width >= flags->preci)
			{
				if (flags->preci < flags->length && flags->preci != 0)
					flags->preci = flags->length;
				i = flags->preci - flags->length;
				if (flags->minusint == 1)
					ft_writeandbyte(flags);
				ft_putzero(i, flags);
				if (flags->preci != 0)
					ft_putnbr_fd(j, flags, 1);
				i = flags->width - flags->preci - flags->minusint;
				ft_putblank(i, flags);
			}
		}
	}
}
