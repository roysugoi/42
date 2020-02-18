/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roy <roy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:57:58 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/18 00:29:09 by roy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int		ft_isvar(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
	c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	ft_flagsinit(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->width = 0;
	flags->widthbool = 0;
	flags->preci = 0;
	flags->precibool = 0;
	flags->variable = 0;
	flags->length = 0;
	flags->adv = 0;
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

void	ft_putblank(int i)
{
	while (i > 0)
	{
		write(1, " ", 1);
		i--;
	}
}