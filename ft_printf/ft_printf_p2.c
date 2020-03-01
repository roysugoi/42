/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:06:59 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/23 22:00:44 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_p5(t_flags *flags, char *v, int i)
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
				i = flags->width - flags->preci - 2;
				ft_putblank(i, flags);
				ft_writezerox(flags);
				i = flags->preci - flags->length;
				ft_putzero(i, flags);
				if (flags->preci != 0)
					ft_putstr_b(v, flags, flags->length);
			}
		}
	}
	ft_printf_p6(flags, v, i);
}

void	ft_printf_p6(t_flags *flags, char *v, int i)
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
				ft_putzero(i, flags);
				if (flags->preci != 0)
					ft_putstr_b(v, flags, flags->length);
				i = flags->width - flags->preci;
				ft_putblank(i, flags);
			}
		}
	}
}

void	ft_writezerox(t_flags *flags)
{
	write(1, "0x", 2);
	flags->bytes = flags->bytes + 2;
}
