/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:43:42 by roy               #+#    #+#             */
/*   Updated: 2020/02/29 15:17:14 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_s(t_flags *flags)
{
	int		i;
	char	*t;

	i = 0;
	if (!(t = va_arg(flags->valist, char*)))
		t = "(null)";
	flags->length = ft_strlen(t);
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
	if (flags->minus == 0 && flags->zero == 0)
		ft_printf_s1(flags, t, i);
	if (flags->minus == 1 && flags->zero == 0)
		ft_printf_s2(flags, t, i);
	if (flags->minus == 0 && flags->zero == 1)
		ft_printf_s1(flags, t, i);
}

void	ft_printf_s1(t_flags *flags, char *s, int i)
{
	ft_printf_s1b(flags);
	if (flags->widthbool == 1 && flags->precibool == 1)
	{
		i = flags->width - flags->preci;
		ft_putblank(i, flags);
		ft_putstr_b(s, flags, (flags->width - i));
	}
	if (flags->widthbool == 0 && flags->precibool == 1)
	{
		if (flags->preci == 0 && flags->percent == 1)
			flags->preci = flags->length;
		ft_putstr_b(s, flags, flags->preci);
	}
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

void	ft_printf_s2(t_flags *flags, char *s, int i)
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

void	ft_printf_s1b(t_flags *flags)
{
	if (flags->preci < 0)
		flags->preci = (flags->preci * -1);
	if (flags->preci > flags->length)
		flags->preci = flags->length;
}
