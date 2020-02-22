/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:01:54 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/21 18:39:00 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	int		k;

	k = 0;
	if (s1 == '\0')
		return (0);
	if (!(aux = (char*)malloc(sizeof(*aux) * (ft_strlen(s1) +
		ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1 != '\0')
	{
		aux[k] = *s1;
		k++;
		s1++;
	}
	while (*s2 != '\0')
	{
		aux[k] = *s2;
		k++;
		s2++;
	}
	aux[k] = '\0';
	return (aux);
}