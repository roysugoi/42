/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:34:24 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/24 00:49:11 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_types(const char *s, t_flags *flags)
{
	if (*s == 'c')
		ft_printf_c(flags);
	if (*s == 's')
		ft_printf_s(flags);
	if (*s == '%')
		ft_printf_pc(flags);
	if (*s == 'i' || *s == 'd')
		ft_printf_i(flags);
	if (*s == 'u')
		ft_printf_u(flags);
	if (*s == 'x' || *s == 'X')
		ft_printf_x(flags, *s);
	if (*s == 'p')
		ft_printf_p(flags);
	++s;
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
			{
				flags->width = flags->width * -1;
				flags->minus = 1;
			}
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
		{
			flags->precibool = 0;
			flags->preci = 0;
		}
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

int		ft_printf_start(const char *s, t_flags *flags)
{
	ft_flagsinit(flags);
	while (*s != '\0')
	{
		if (*s != '%')
		{
			write(1, s, 1);
			flags->bytes++;
		}
		else
		{
			flags->adv++;
			ft_printf_flags1(s, flags);
			if (flags->bytes >= 0)
				s = s + flags->adv;
			ft_flagsinit(flags);
		}
		s++;
	}
	return (flags->bytes);
}

int		ft_printf(const char *s, ...)
{
	t_flags	flags;
	int		bytes;

	if (!s)
		return (0);
	flags.bytes = 0;
	va_start(flags.valist, s);
	ft_flagsinit(&flags);
	bytes = ft_printf_start(s, &flags);
	flags.bytes = 0;
	va_end(flags.valist);
	return (bytes);
}
