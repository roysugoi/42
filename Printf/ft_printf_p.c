/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 23:19:38 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/23 00:16:07 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_x(t_flags *flags, char s)
{
	int		i;
	int		j;
	char	*t;

	i = 0;
	if (!(j = (va_arg(flags->valist, int))))
		j = 0;
	if (s == 'x')
		t = ft_itoahex(j);
}

int		get_digits(long n)
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

char	*ft_itoahex(long n)
{
	int		digits;
	long	numb;
	char	*str;

	numb = n;
	digits = get_digits(numb);
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

char	*ft_itoahexupper(long n)
{
	int		digits;
	long	numb;
	char	*str;

	numb = n;
	digits = get_digits(numb);
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
