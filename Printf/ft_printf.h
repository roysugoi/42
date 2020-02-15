/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roy <roy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:58:05 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/15 15:45:23 by roy              ###   ########.fr       */
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
}					t_flags;
void	ft_putchar_fd(char c, int fd);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
void	ft_flagszero(t_flags *flags);
int		ft_isvar(char c);
int		ft_atoi(const char *s);
int		ft_atoi_counter(int i);
void	ft_flagsinit(t_flags *flags);

#endif
