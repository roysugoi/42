/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roy <roy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:36:20 by rvegas-j          #+#    #+#             */
/*   Updated: 2019/12/12 19:27:32 by roy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &(s[i]), 1);
		i++;
	}
}

int		ft_atoi(const char *str)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
	|| str[i] == '\f' || str[i] == '\r')
		i++;
	while ((str[i] >= '0' && (str[i] <= '9')))
	{
		num *= 10;
		num += (str[i] - '0');
		i++;
	}
	return (num);
}

int		ft_isvar(char s)
{
	if (s == 'c' || s == 's' || s == 'p' ||
	s == 'd' || s == 'i' || s == 'u' ||
	s == 'x' || s == 'X')
		return (1);
	return (0);	
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}