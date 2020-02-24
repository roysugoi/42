/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 18:58:26 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/24 18:59:05 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_flags1b(t_flags *flags)
{
	flags->width = flags->width * -1;
	flags->minus = 1;
}

int		ft_printf_flags1(const char *s, t_flags *flags)
{
	if (++s != '\0')
	{
		while (*s == '-' || *s == '0')
		{
			if (*s == '-')
				flags->minus = 1 && flags->adv++;
			if (*s == '0')
				flags->zero = 1 && flags->adv++;
			s++;
		}
		if (*s == '*')
		{
			flags->width = va_arg(flags->valist, int);
			if (flags->widthbool == 1 && flags->width < 0)
				flags->width = flags->width * (-1);
			flags->widthbool = 1 && ++s && flags->adv++;
			if (flags->width < 0)
				ft_printf_flags1b(flags);
		}
		ft_printf_flags2(s, flags);
		return (0);
	}
	else
		return (-1);
}

void	ft_printf_flags2(const char *s, t_flags *flags)
{
	while (ft_isdigit(*s) && *s != '\0')
	{
		flags->width = flags->width * 10 + (*s - '0');
		flags->widthbool = 1 && flags->adv++ && ++s;
	}
	if (*s == '.')
		flags->precibool = 1 && flags->adv++ && ++s;
	if (*s == '*')
	{
		(flags->preci = va_arg(flags->valist, int));
		if (flags->preci < 0)
			ft_printf_flags2b(flags);
		flags->adv++;
		++s;
	}
	while (ft_isdigit(*s) && flags->precibool == 1 && *s != '\0')
	{
		flags->preci = flags->preci * 10 + (*s - '0');
		flags->adv++ && ++s;
	}
	if (*s != '\0')
		ft_printf_types(s, flags);
	else
		flags->bytes = -1;
}

void	ft_printf_flags2b(t_flags *flags)
{
	flags->precibool = 0;
	flags->preci = 0;
}
