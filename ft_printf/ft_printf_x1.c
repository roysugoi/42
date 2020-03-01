/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:50:11 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/29 16:15:08 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_x(t_flags *flags, char c)
{
	int				i;
	unsigned int	j;
	char			*v;

	i = 0;
	if (!(j = (va_arg(flags->valist, unsigned int))))
		j = 0;
	if (c == 'x')
		v = ft_itoahexc(j);
	if (c == 'X')
		v = ft_itoahexupper(j);
	flags->length = ft_strlen(v);
	ft_printf_x1(flags, v, i);
}

void	ft_printf_x1(t_flags *flags, char *v, int i)
{
	if (flags->widthbool == 0 && flags->precibool == 0)
		ft_putstr_b(v, flags, flags->length);
	ft_printf_x2(flags, v, i);
}

void	ft_printf_x2(t_flags *flags, char *v, int i)
{
	if (flags->widthbool == 1 && flags->precibool == 0)
	{
		if (flags->zero == 0)
		{
			i = flags->width - flags->length;
			if (flags->minus == 0)
			{
				ft_putblank(i, flags);
				ft_putstr_b(v, flags, flags->length);
			}
			if (flags->minus == 1)
			{
				ft_putstr_b(v, flags, flags->length);
				ft_putblank(i, flags);
			}
		}
	}
	ft_printf_x3(flags, v, i);
}

void	ft_printf_x3(t_flags *flags, char *v, int i)
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
	ft_printf_x4(flags, v, i);
}

void	ft_printf_x4(t_flags *flags, char *v, int i)
{
	if (flags->widthbool == 0 && flags->precibool == 1)
	{
		i = flags->preci - flags->length;
		ft_putzero(i, flags);
		if (flags->preci == 0)
		{
			if (*v != '0')
				ft_putstr_b(v, flags, flags->length);
		}
		else
			ft_putstr_b(v, flags, flags->length);
	}
	ft_printf_x5(flags, v, i);
}
