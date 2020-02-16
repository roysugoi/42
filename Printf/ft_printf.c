/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roy <roy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:34:24 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/16 02:32:10 by roy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		ft_printf_var(const char *s, t_flags *flags) //ME HE QUEDADO EN QUE NO SE COMO AVANZAR 1 DESPUÉS DE IMPRIMIR EN LA FUNCIÓN CORRESPONDIENTE.
{
	//if (*s == 'c')
	//	ft_printf_c(s, flags);
	if (*s == 's')
		ft_printf_s(flags);
	//if (*s == 'p')
	//	ft_printf_p(s, flags);
	//if (*s == 'd')
	//	ft_printf_d(s, flags);
	//if (*s == 'i')
	//	ft_printf_i(s, flags);
	//if (*s == 'u')
	//	ft_printf_u(s, flags);
	//if (*s == 'x')
	//	ft_printf_x(s, flags);
	//if (*s == 'X')
	//	ft_printf_X(s, flags);
	//if (*s == '%')
	//	ft_printf_percent(s, flags);
	++s;
	return (0);
}

int		ft_printf_flags(const char *s, t_flags *flags)				//FALTAN ASTERISK
{
	s++;
	if (*s == '-')
		flags->minus = 1 && ++s && flags->advance++;
	if (*s == '0')
		flags->zero = 1 && ++s && flags->advance++;
	while (ft_isdigit(*s))
	{
		flags->minwidth = flags->minwidth * 10 + (*s - '0');
		flags->minwidthbool = 1;
		flags->advance++;
		++s;
	}
	if (*s == '.')
		flags->precissionbool = 1 && flags->advance++ && ++s;
	while (ft_isdigit(*s))
	{
		flags->precission = flags->precission * 10 + (*s - '0');
		++s;
		flags->advance++;
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
			//printf("\nMinus flag: %i\nZero flag: %i\nMinWidth flag: %i\nMinWidth Bool: %i\nPrecission Flag: %i\nPrecission Bool: %i\nAdvance: %i\n", flags->minus, flags->zero, flags->minwidth, flags->minwidthbool, flags->precission, flags->precissionbool, flags->advance);
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
	printf("\n\nBytes: %i\n", flags->bytes);
	free(flags);
	return (bytes);
}

int		main(void)
{
	char *s;
	char *t;
	
	s = "hola";
	t = "y tal";
	printf("\nResultado printf:\n");
	printf("Pues %-6.2s mundo %.3s y cual.", s, t);
	printf("\n");
	printf("\nResultado ft_printf:\n");
	ft_printf("Pues %-6.2s mundo %.3s y cual.", s, t);
	printf("\n");
}
