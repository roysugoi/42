/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roy <roy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:34:24 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/15 15:48:17 by roy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_flags(const char *s, t_flags *flags)
{
	if (*s == '-')
		flags->minus = 1 && ++s;
	if (*s == '0')
		flags->zero = 1 && ++s;
	while (ft_isdigit(*s))
	{
		flags->minwidth = flags->minwidth * 10 + (*s - '0');
		flags->minwidthbool = 1;
		++s;
	}
	if (*s == '.')
		flags->precissionbool = 1 && ++s;
	if (ft_isdigit(*s))
		flags->precission = flags->precission * 10 + (*s - '0');
	return (0);
}

int		ft_printf_start(const char *s, t_flags *flags)
{
	ft_flagsinit(flags);
	while (*s != '\0')
	{
		if (*s != '%')
			write(1, s, 1);
		else
		{
			ft_printf_flags(++s, flags);
			s = s + flags->advance;
		}
		s++;
	}
	return (0);
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
	printf("\nMinus flag: %i\nZero flag: %i\nMinWidth flag: %i\nMinWidth Bool Flag: %i\nPrecission Flag: %i\nPrecission Bool Flag: %i\nAdvance: %i\n", flags->minus, flags->zero, flags->minwidth, flags->minwidthbool, flags->precission, flags->precissionbool, flags->advance);
	free(flags);
	return (bytes);
}

int		main(void)
{
	char *s;
	s = "hola";
	ft_printf("Pues %04207.2s mundo.", s);
}
