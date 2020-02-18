/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roy <roy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:43:42 by roy               #+#    #+#             */
/*   Updated: 2020/02/18 01:42:44 by roy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_s(t_flags *flags)
{
	int		i;
	int		j;
	char	*s;
	
	i = 0;
	j = 0;
	s = ft_strdup(va_arg(flags->valist, char*));
	flags->length = ft_strlen(s);
	if (flags->minus == 0 && flags->zero == 0)
		ft_printf_s1(flags, s, i, j);
}

void	ft_printf_s1(t_flags *flags, char * s, int i, int j)
{
	if (flags->widthbool == 1 && flags->precibool == 1)
	{
		if (flags->preci > flags->length)
			flags->preci = flags->length;
		i = flags->width - flags->preci;
		j = flags->width - i;
		ft_putblank(i);
		ft_putstr_b(s, flags, j);
	}
	if (flags->widthbool == 0 && flags->precibool == 1)
	{
		if (flags->preci > flags->length)
			flags->preci = flags->length;
		ft_putstr_b(s, flags, flags->preci);
	}
	if (flags->widthbool == 1 && flags->precibool == 0)
	{
		i = flags->width - flags->length;
		j = flags->width - i;
		ft_putblank(i);
		ft_putstr_b(s, flags, j);
	}
	if (flags->widthbool == 0 && flags->precibool == 0)
		ft_putstr_a(s, flags);
}
