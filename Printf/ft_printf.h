/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:58:05 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/26 17:50:47 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H
# include "unistd.h"
# include "stdlib.h"
# include "stdio.h"
# include "stdarg.h"
# include "limits.h"

typedef unsigned long int	t_uli;
typedef unsigned long long	t_ull;

typedef struct		s_flags
{
	va_list			valist;
	int				zero;
	int				minus;
	int				width;
	int				widthbool;
	int				preci;
	int				precibool;
	int				length;
	int				adv;
	int				bytes;
	int				minusint;
	char			*itoahex;
	int				max;
	int				percent;
	int				zeroarg;
}					t_flags;
int					ft_isdigit(int c);
void				ft_putstr_a(char *s, t_flags *flags);
void				ft_putstr_b(char *s, t_flags *flags, int j);
void				ft_putblank(int i, t_flags *flags);
void				ft_putzero(int i, t_flags *flags);
int					ft_isvar(char c);
int					ft_atoi(const char *s);
int					ft_strlen(const char *str);
void				ft_flagsinit(t_flags *flags);
int					ft_printf_flags1(const char *s, t_flags *flags);
void				ft_printf_flags1b(t_flags *flags);
void				ft_printf_flags2(const char *s, t_flags *flags);
void				ft_printf_flags2b(t_flags *flags);
void				ft_printf_types(const char *s, t_flags *flags);
void				ft_printf_s(t_flags *flags);
void				ft_printf_s1(t_flags *flags, char *s, int i);
void				ft_printf_s1b(t_flags *flags);
void				ft_printf_s2(t_flags *flags, char *s, int i);
void				ft_printf_c(t_flags *flags);
void				ft_printf_c1(t_flags *flags, int s, int i);
void				ft_printf_c2(t_flags *flags, int s, int i);
int					ft_printf(const char *s, ...);
void				ft_printf_pc(t_flags *flags);
void				ft_printf_pc1(t_flags *flags, char *s, int i);
t_ull				ft_numofdigits(t_ull i);
void				ft_printf_i(t_flags *flags);
void				ft_printf_i1(t_flags *flags, int j, int i);
void				ft_printf_i2(t_flags *flags, int j, int i);
void				ft_printf_i3(t_flags *flags, int j, int i);
void				ft_printf_i4(t_flags *flags, int j, int i);
void				ft_printf_i5(t_flags *flags, int j, int i);
void				ft_printf_i6(t_flags *flags, int j, int i);
void				ft_printf_u(t_flags *flags);
void				ft_printf_u1(t_flags *flags, unsigned long j, int i);
void				ft_printf_u2(t_flags *flags, unsigned long j, int i);
void				ft_printf_u3(t_flags *flags, unsigned long j, int i);
void				ft_printf_u4(t_flags *flags, unsigned long j, int i);
void				ft_printf_u5(t_flags *flags, unsigned long j, int i);
void				ft_printf_u6(t_flags *flags, unsigned long j, int i);
void				ft_printf_x(t_flags *flags, char c);
void				ft_printf_x1(t_flags *flags, char *v, int i);
void				ft_printf_x2(t_flags *flags, char *v, int i);
void				ft_printf_x3(t_flags *flags, char *v, int i);
void				ft_printf_x4(t_flags *flags, char *v, int i);
void				ft_printf_x5(t_flags *flags, char *v, int i);
void				ft_printf_x6(t_flags *flags, char *v, int i);
void				ft_putnbr_fd(long long n, t_flags *flags, int fd);
void				ft_printf_p(t_flags *flags);
void				ft_printf_p1(t_flags *flags, char *v, int i);
void				ft_printf_p2(t_flags *flags, char *v, int i);
void				ft_printf_p3(t_flags *flags, char *v, int i);
void				ft_printf_p4(t_flags *flags, char *v, int i);
void				ft_printf_p5(t_flags *flags, char *v, int i);
void				ft_printf_p6(t_flags *flags, char *v, int i);
void				ft_putnbr_fd_ui(t_ull n, t_flags *flags, int fd);
void				ft_putchar_fd(char c, t_flags *flags, int fd);
void				ft_writeandbyte(t_flags *flags);
int					ft_getdigits(t_ull n);
char				*ft_itoahex(t_uli n);
char				*ft_itoahexb(t_uli n, t_flags *flags, int dgt, t_uli nu);
char				*ft_itoahexupper(t_uli n);
void				ft_writezerox(t_flags *flags);

#endif
