/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roy <roy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:58:05 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/15 21:15:47 by roy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include "unistd.h"
# include "stdlib.h"
# include "stdio.h"
# include "stdarg.h"

typedef struct		s_flags
{
	va_list			valist;
	int				zero;
	int				minus;
	int				minwidth;
	int				minwidthbool;
	int				precission;
	int				precissionbool;
	int				variable;
	int				advance;
	int				bytes;
}					t_flags;
void	ft_putchar_fd(char c, int fd);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, t_flags *flags);
void	ft_flagszero(t_flags *flags);
int		ft_isvar(char c);
int		ft_atoi(const char *s);
int		ft_atoi_counter(int i);
void	ft_flagsinit(t_flags *flags);
//int		ft_printf_c(const char *s, t_flags *flags);
int		ft_printf_s(const char *s, t_flags *flags);
//int		ft_printf_p(const char *s, t_flags *flags);
//int		ft_printf_d(const char *s, t_flags *flags);
//int		ft_printf_i(const char *s, t_flags *flags);
//int		ft_printf_u(const char *s, t_flags *flags);
//int		ft_printf_x(const char *s, t_flags *flags);
//int		ft_printf_X(const char *s, t_flags *flags);
//int		ft_printf_percent(const char *s, t_flags *flags);

#endif
