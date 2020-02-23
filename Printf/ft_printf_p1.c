/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:50:11 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/23 22:27:55 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_p(t_flags *flags)
{
	int				i;
	unsigned int	j;
	char			*v;

	i = 0;
	j = (va_arg(flags->valist, unsigned int));
	v = ft_itoahexb(j, flags);
	flags->length = ft_strlen(v);
	ft_printf_p1(flags, v, i);
}

void	ft_printf_p1(t_flags *flags, char *v, int i)
{
	if (flags->widthbool == 0 && flags->precibool == 0)
	{
		ft_writezerox(flags);
		ft_putstr_b(v, flags, flags->length);
	}
	ft_printf_p2(flags, v, i);
}

void	ft_printf_p2(t_flags *flags, char *v, int i)
{
	if (flags->widthbool == 1 && flags->precibool == 0)
	{
		if (flags->zero == 0)
		{
			i = flags->width - flags->length - 2;
			if (flags->minus == 0)
			{
				ft_putblank(i, flags);
				ft_writezerox(flags);
				ft_putstr_b(v, flags, flags->length);
			}
			if (flags->minus == 1)
			{
				ft_putstr_b(v, flags, flags->length);
				ft_putblank(i, flags);
			}
		}
	}
	ft_printf_p3(flags, v, i);
}

void	ft_printf_p3(t_flags *flags, char *v, int i)
{
	if (flags->widthbool == 1 && flags->precibool == 0)
	{
		if (flags->zero == 1)
		{
			i = flags->width - flags->length;
			ft_putzero(i, flags);
			ft_putstr_b(v, flags, flags->length);
		}
	}
	ft_printf_p4(flags, v, i);
}

void	ft_printf_p4(t_flags *flags, char *v, int i)
{
	if (flags->widthbool == 0 && flags->precibool == 1)
	{
		i = flags->preci - flags->length;
		if (i >= 0)
		{
			ft_writezerox(flags);
			ft_putzero(i, flags);
			ft_putstr_b(v, flags, flags->length);
		}
		else
		{
			ft_writezerox(flags);
			ft_putstr_b(v, flags, flags->length);
		}
	}
	ft_printf_p5(flags, v, i);
}
