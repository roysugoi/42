/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 22:47:16 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/21 16:50:23 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_p(t_flags *flags)
{
	int		i;
	long	n;
	char	*t;
	char	*s;

	i = 0;
	if ((n = va_arg(flags->valist, long)))
	{
		t = ft_itoahex(n);
		s = ft_strjoin("0x", t);
	}
	else
		s = "0";
	flags->length = ft_strlen(s);
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
	if (flags->minus == 0 && flags->zero == 0)
		ft_printf_s1(flags, s, i);
	if (flags->minus == 1 && flags->zero == 0)
		ft_printf_s2(flags, s, i);
	if (flags->minus == 0 && flags->zero == 1)
		ft_printf_s1(flags, s, i);
}

void	ft_printf_p1(t_flags *flags, char *s, int i)
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
		ft_putstr_b(s, flags, (flags->width - i));
	}
	if (flags->widthbool == 0 && flags->precibool == 1)
		ft_putstr_b(s, flags, flags->preci);
	if (flags->widthbool == 1 && flags->precibool == 0)
	{
		i = flags->width - flags->length;
		if (flags->zero == 1)
			ft_putzero(i, flags);
		else
			ft_putblank(i, flags);
		ft_putstr_b(s, flags, (flags->width - i));
	}
	if (flags->widthbool == 0 && flags->precibool == 0)
		ft_putstr_a(s, flags);
}

void	ft_printf_p2(t_flags *flags, char *s, int i)
{
	if (flags->widthbool == 1 && flags->precibool == 1)
	{
		if (flags->preci > flags->length)
			flags->preci = flags->length;
		i = flags->width - flags->preci;
		ft_putstr_b(s, flags, (flags->width - i));
		ft_putblank(i, flags);
	}
	if (flags->widthbool == 0 && flags->precibool == 1)
	{
		if (flags->preci > flags->length)
			flags->preci = flags->length;
		ft_putstr_b(s, flags, flags->preci);
	}
	if (flags->widthbool == 1 && flags->precibool == 0)
	{
		i = flags->width - flags->length;
		ft_putstr_b(s, flags, (flags->width - i));
		ft_putblank(i, flags);
	}
	if (flags->widthbool == 0 && flags->precibool == 0)
		ft_putstr_a(s, flags);
}
