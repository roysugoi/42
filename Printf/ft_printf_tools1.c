/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:57:58 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/22 19:04:21 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flagsinit(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->widthbool = 0;
	flags->preci = 0;
	flags->precibool = 0;
	flags->length = 0;
	flags->adv = 0;
	flags->minusint = 0;
}

void	ft_putstr_a(char *s, t_flags *flags)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			flags->bytes++;
			i++;
		}
	}
}

void	ft_putstr_b(char *s, t_flags *flags, int j)
{
	int	i;

	i = 0;
	if (s)
	{
		while (j > 0)
		{
			write(1, &s[i], 1);
			flags->bytes++;
			i++;
			j--;
		}
	}
}

void	ft_putblank(int i, t_flags *flags)
{
	while (i > 0)
	{
		write(1, " ", 1);
		flags->bytes++;
		i--;
	}
}

void	ft_putzero(int i, t_flags *flags)
{
	while (i > 0)
	{
		write(1, "0", 1);
		flags->bytes++;
		i--;
	}
}
