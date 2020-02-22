/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:34:24 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/22 11:06:32 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_types(const char *s, t_flags *flags)
{
	if (*s == 'c')
		ft_printf_c(flags);
	if (*s == 's')
		ft_printf_s(flags);
	if (*s == 'p')
		ft_printf_p(flags);
	if (*s == '%')
		ft_printf_pc(flags);
	++s;
}

void	ft_printf_flags1(const char *s, t_flags *flags)
{
	++s;
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
		flags->widthbool = 1 && ++s && flags->adv++;
		if (flags->width < 0)
		{
			flags->width = flags->width * -1;
			flags->minus = 1;
		}
	}
	ft_printf_flags2(s, flags);
}

void	ft_printf_flags2(const char *s, t_flags *flags)
{
	while (ft_isdigit(*s))
	{
		flags->width = flags->width * 10 + (*s - '0');
		flags->widthbool = 1 && flags->adv++ && ++s;
	}
	if (*s == '.')
		flags->precibool = 1 && flags->adv++ && ++s;
	if (*s == '*')
		(flags->preci = va_arg(flags->valist, int)) && flags->adv++ && ++s;
	while (ft_isdigit(*s) && flags->precibool == 1)
	{
		flags->preci = flags->preci * 10 + (*s - '0');
		flags->adv++ && ++s;
	}
	ft_printf_types(s, flags);
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
			s = s + flags->adv;
			ft_flagsinit(flags);
		}
		s++;
	}
	return (flags->bytes);
}

int		ft_printf(const char *s, ...)
{
	t_flags	*flags;
	int		bytes;

	if (!s)
		return (0);
	if (!(flags = (t_flags *)malloc(sizeof(flags))))
		return (-1);
	flags->bytes = 0;
	va_start(flags->valist, s);
	ft_flagsinit(flags);
	bytes = ft_printf_start(s, flags);
	flags->bytes = 0;
	va_end(flags->valist);
	free(flags);
	return (bytes);
}
