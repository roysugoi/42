/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:58:05 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/19 17:23:12 by rvegas-j         ###   ########.fr       */
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
	int				width;
	int				widthbool;
	int				preci;
	int				precibool;
	int				variable;
	int				length;
	int				adv;
	int				bytes;
}					t_flags;
int		ft_isdigit(int c);
void	ft_putstr_a(char *s, t_flags *flags);
void	ft_putstr_b(char *s, t_flags *flags, int j);
void	ft_putblank(int i, t_flags *flags);
void	ft_flagszero(t_flags *flags);
int		ft_isvar(char c);
int		ft_atoi(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
void	ft_flagsinit(t_flags *flags);
void	ft_printf_flags1(const char *s, t_flags *flags);
void	ft_printf_flags2(const char *s, t_flags *flags);
int		ft_printf_types(const char *s, t_flags *flags);
void	ft_printf_s(t_flags *flags);
void	ft_printf_s1(t_flags *flags, char * s, int i);
void	ft_printf_s2(t_flags *flags, char * s, int i);

#endif
