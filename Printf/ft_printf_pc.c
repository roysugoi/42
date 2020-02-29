/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:01:39 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/29 16:38:27 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_pc(t_flags *flags)
{
	int		i;
	char	*t;

	i = 0;
	t = "%";
	flags->length = ft_strlen(t);
	flags->percent = 1;
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
	if (flags->minus == 0 && flags->zero == 0)
		ft_printf_s1(flags, t, i);
	if (flags->minus == 1 && flags->zero == 0)
		ft_printf_pc2(flags, t, i);
	if (flags->minus == 0 && flags->zero == 1)
		ft_printf_s1(flags, t, i);
}

void	ft_printf_pc2(t_flags *flags, char *s, int i)
{
	if (flags->widthbool == 1 && flags->precibool == 1)
	{
		if (flags->preci > flags->length)
			flags->preci = flags->length;
		i = flags->width - flags->preci;
		if (flags->preci != 0)
		{
			ft_putstr_b(s, flags, (flags->width - i));
			ft_putblank(i, flags);
		}
		else
		{
			ft_putstr_b(s, flags, 1);
			ft_putblank(i - 1, flags);
		}
	}
	ft_printf_pc3(flags, s, i);
}

void	ft_printf_pc3(t_flags *flags, char *s, int i)
{
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
