/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:43:42 by roy               #+#    #+#             */
/*   Updated: 2020/02/18 19:42:51 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_s(t_flags *flags)
{
	int		i;
	char	*s;

	i = 0;
	if (!(s = va_arg(flags->valist, char*)))
		s = ft_strdup("(null)");
	if (s == NULL)
		flags->length = 0;
	flags->length = ft_strlen(s);
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
	if (flags->minus == 0 && flags->zero == 0)
		ft_printf_s1(flags, s, i);
	if (flags->minus == 1 && flags->zero == 0)
		ft_printf_s2(flags, s, i);
	if (flags->minus == 0 && flags->zero == 1)
		ft_printf_s1(flags, s, i);
	ft_flagsinit(flags);
}

void	ft_printf_s1(t_flags *flags, char *s, int i)
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
		ft_putblank(i);
		ft_putstr_b(s, flags, (flags->width - i));
	}
	if (flags->widthbool == 0 && flags->precibool == 1)
		ft_putstr_b(s, flags, flags->preci);
	if (flags->widthbool == 1 && flags->precibool == 0)
	{
		i = flags->width - flags->length;
		ft_putblank(i);
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
		ft_putblank(i);
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
		ft_putblank(i);
	}
	if (flags->widthbool == 0 && flags->precibool == 0)
		ft_putstr_a(s, flags);
}
