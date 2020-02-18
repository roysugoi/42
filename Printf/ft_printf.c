/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roy <roy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:34:24 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/18 03:17:49 by roy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_types(const char *s, t_flags *flags)
{
	if (*s == 's')
		ft_printf_s(flags);
	++s;
	return (0);
}

void	ft_printf_flags(const char *s, t_flags *flags)
{
	if (*++s == '-')
		flags->minus = 1 && ++s && flags->adv++;
	if (*s == '0')
		flags->zero = 1 && ++s && flags->adv++;
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
	while (ft_isdigit(*s))
	{
		flags->width = flags->width * 10 + (*s - '0');
		flags->widthbool = 1 && ++s && flags->adv++;
	}
	if (*s == '.')
		flags->precibool = 1 && ++s && flags->adv++;
	if (*s == '*')
		(flags->preci = va_arg(flags->valist, int)) && ++s && flags->adv++;
	while (ft_isdigit(*s))
	{
		flags->preci = flags->preci * 10 + (*s - '0');
		++s;
		flags->adv++;
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
			ft_printf_flags(s, flags);
			s = s + flags->adv;
			//printf("\n\nMinus flag: %i\nZero flag: %i\nWidth: %i\nWidthBool: %i\nPreci: %i\nPreciBool: %i\nAdvance: %i\n", flags->minus, flags->zero, flags->width, flags->widthbool, flags->preci, flags->precibool, flags->adv);ft_flagsinit(flags);
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

	printf("\n\n");
	printf("\nReturn printf: %d", printf("Pues %*.1s mundo.", 2, s));

	
	printf("\n\nResultado printf:\n");
	printf("Pues %*.*s mundo.", 20, 15, s);
	printf("\n");
	printf("\nResultado ft_printf:\n");
	ft_printf("Pues %*.*s mundo.", 20, 15, s);
	printf("\n");
}


//SI PONGO ASTERISCOS Y NO PONGO UN ARGUMENTO, PROTEGER.
//REPASAR BYTES ESCRITOS.