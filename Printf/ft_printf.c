/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:34:24 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/12 18:57:02 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf_flags(const char *s, t_flags *flags)
{
	int	counter;

	counter = 0;
	while (ft_isvar(*s))
	{
		if (*++s == '0')
			flags->zero = 1;
		if (*++s == '-')
			flags->minus = 1;
		if (ft_isdigit((int)*++s))
			flags->minwidth = 1;		//Alberto me comenta que conviene guardar el booleano de activación del flag pero conservar e valor del entero dentro también de la estrcutura, sabiendo que está activado y que es X.
		if ()
	}
	return (0);
}

int		ft_printf_start(const char *s, t_flags *flags)
{
	char *a;

	ft_flagsinit(&flags);
	while (*s != '\0')
	{
		if (*s != '%')
			write(1, s, 1);
		else
			ft_printf_flags(s, flags);
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
	ft_flagszero(flags);
	bytes = ft_printf_start(s, *flags);
	va_end(flags->valist);
	free(flags);
	return (bytes);
}

int		main(void)
{
	char *s;
	char *t;

	s = "hola";
	t = "y tal";
	ft_printf("Pues %s mundo %s.", s, t);
	ft_printf("\n");
}
