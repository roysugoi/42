/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/23 00:29:05 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/23 23:24:30 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnbr_fd(int n, t_flags *flags, int fd)
{
	if (n == -2147483648)
		ft_putstr_a("-2147483648", flags);
	else if (n < 0)
	{
		ft_putchar_fd('-', flags, fd);
		ft_putnbr_fd(-n, flags, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, flags, fd);
		ft_putchar_fd(n % 10 + '0', flags, fd);
	}
	else
		ft_putchar_fd(n + '0', flags, fd);
}

int			ft_getdigits(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char		*ft_itoahex(unsigned int n)
{
	int		digits;
	long	numb;
	char	*str;

	numb = n;
	digits = ft_getdigits(numb);
	if (!(str = malloc((digits + 1) * sizeof(char))))
		return (NULL);
	str[digits--] = '\0';
	if (numb == 0)
		str[0] = '0';
	while (numb > 0)
	{
		if (numb % 16 <= 9)
			str[digits] = numb % 16 + '0';
		else if (numb % 16 < 16)
			str[digits] = numb % 16 + 'W';
		numb /= 16;
		digits--;
	}
	return (str);
}

char		*ft_itoahexb(unsigned long int n, t_flags *flags, int dgt, long numb)
{
	char	*str;

	if (n)
	{
		numb = n;
		dgt = ft_getdigits(numb);
		if (!(str = malloc((dgt + 1) * sizeof(char))))
			return (NULL);
		str[dgt--] = '\0';
		if (numb == 0)
			str[0] = '0';
		while (numb > 0)
		{
			if (numb % 16 <= 9)
				str[dgt] = numb % 16 + '0';
			else if (numb % 16 < 16)
				str[dgt] = numb % 16 + 'W';
			numb /= 16;
			dgt--;
		}
		return (str);
	}
	if (flags->preci == 0 && flags->precibool == 1)
		return ("");
	return ("0");
}

char		*ft_itoahexupper(unsigned long int n)
{
	int		digits;
	long	numb;
	char	*str;

	numb = n;
	digits = ft_getdigits(numb);
	if (!(str = malloc((digits + 1) * sizeof(char))))
		return (NULL);
	str[digits--] = '\0';
	if (numb == 0)
		str[0] = '0';
	while (numb > 0)
	{
		if (numb % 16 <= 9)
			str[digits] = numb % 16 + '0';
		else if (numb % 16 < 16)
			str[digits] = numb % 16 + 55;
		numb /= 16;
		digits--;
	}
	return (str);
}

void		ft_putzero(int i, t_flags *flags)
{
	while (i > 0)
	{
		write(1, "0", 1);
		flags->bytes++;
		i--;
	}
}
