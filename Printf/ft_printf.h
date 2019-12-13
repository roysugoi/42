/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roy <roy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 17:50:25 by rvegas-j          #+#    #+#             */
/*   Updated: 2019/12/12 19:54:19 by roy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef	struct	s_flags
{
	int			minus;
	int			zero;
	int			minwidth;
	int			asterisk1;
	int			dot;
	int			maxwidth;
	int			asterisk2;
	char		variable;
	va_list		args;
}				t_flags;

int		ft_printf(const char *format, ...);
void	t_flags_init(t_flags *flag);
void	ft_putstr(char const *s);
int		ft_atoi(const char *str);
int		ft_isvar(char s);
void	ft_putchar(char c);

#endif
