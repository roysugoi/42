/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roy <roy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:57:58 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/15 20:11:47 by roy              ###   ########.fr       */
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
	flags->minwidth = 0;
	flags->minwidthbool = 0;
	flags->precission = 0;
	flags->precissionbool = 0;
	flags->variable = 0;
	flags->advance = 0;
}

void	ft_putstr_fd(char *s, t_flags *flags)
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

int		ft_atoi(const char *str)
{
	int					i;
	unsigned long long	n;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n);
}

int		ft_atoi_counter(int i)
{
	int j;
	while (i / 10 >= 1)
		j++;
	j++;
	return (j);
}
