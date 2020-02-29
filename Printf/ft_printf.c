/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:34:24 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/29 15:53:15 by rvegas-j         ###   ########.fr       */
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
