/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roy <roy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 17:39:22 by rvegas-j          #+#    #+#             */
/*   Updated: 2019/12/13 16:04:56 by roy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_activator(char r, char s, char t)
{
	t_flags	*flags;

	flags = 0;
	t_flags_init(flags);
	if (s == '-')
		flags->minus = 1;
	if (s == '*' && t == '.')
		flags->asterisk1 = 1;
	if (s == '.')
		flags->dot = 1;
	if (s == '*' && t != '.')
		flags->asterisk2 = 1;
	if (s > '0' && s <= '9' && r != '.')
		flags->minwidth = 1;
	if (s > '0' && s <= '9' && r == '.')
		flags->maxwidth = 1;
}

int		ft_string_trimmer(const char *s, va_list list)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '%')
			ft_putchar(s[i]);
		else	
		{
			++i;
			if (s[i] == 's')
				ft_putstr(va_arg(list, char*));
		}
		i++;
	}
	return (0);
}

int		ft_printf(const char *s, ...)
{
	va_list	list;
	
	va_start(list, s);
	if (!s)
		return (0);
	ft_string_trimmer(s, list);
	va_end(list);
	return (1);
}
