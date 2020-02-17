/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:34:24 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/17 19:13:08 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_var(const char *s, t_flags *flags)
{
	if (*s == 's')
		ft_printf_s(flags);
	++s;
	return (0);
}

int		ft_printf_flags(const char *s, t_flags *flags)
{
	s++;
	if (*s == '-')
	{
		flags->minus = 1;
		++s;
		flags->advance++;
	}
	if (*s == '0')
	{
		flags->zero = 1;
		++s;
		flags->advance++;
	}
	if (*s == '*')
	{
		flags->minwidth = va_arg(flags->valist, int);
		++s;
		flags->advance++;
		if (flags->minwidth < 0)
		{
			flags->minwidth = flags->minwidth * -1;
			flags->minus = 1;
		}
	}
	while (ft_isdigit(*s))
	{
		flags->minwidth = flags->minwidth * 10 + (*s - '0');
		flags->minwidthbool = 1;
		++s;
		flags->advance++;
	}
	if (*s == '.')
	{
		flags->precissionbool = 1;
		flags->advance++;
		++s;
	}
	if (*s == '*')
	{
		flags->precission = va_arg(flags->valist, int);
		++s;
		flags->advance++;
	}
	while (ft_isdigit(*s))
	{
		flags->precission = flags->precission * 10 + (*s - '0');
		++s && flags->advance++;
	}
	if (ft_isvar(*s))
		ft_printf_var(s, flags);
	return (0);
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
			flags->advance++;
			ft_printf_flags(s, flags);
			s = s + flags->advance;
			//printf("\n\nMinus flag: %i\nZero flag: %i\nMinWidth flag: %i\nMinWidth Bool: %i\nPrecission Flag: %i\nPrecission Bool: %i\nAdvance: %i\n", flags->minus, flags->zero, flags->minwidth, flags->minwidthbool, flags->precission, flags->precissionbool, flags->advance);
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
	if (!(flags = malloc(sizeof(*flags))))
		return (-1);
	va_start(flags->valist, s);
	ft_flagsinit(flags);
	bytes = ft_printf_start(s, flags);
	va_end(flags->valist);
	printf("\n\nBytes escritos: %i\n", flags->bytes);
	free(flags);
	return (bytes);
}

int		main(void)
{
	char *s;

	s = "hola";
	printf("\033[1;35m");
	printf("Resultado printf:\n");
	printf("Pues %*.2s mundo.", -6, s);
	printf("\033[0m");
	printf("\n");
	printf("\nResultado ft_printf:\n");
	ft_printf("Pues %*.2s mundo.", -6, s);
	printf("\n");
}
