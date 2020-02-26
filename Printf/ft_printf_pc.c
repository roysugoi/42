/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 11:01:39 by rvegas-j          #+#    #+#             */
/*   Updated: 2020/02/25 19:32:00 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_pc(t_flags *flags)
{
	int		i;
	char	*t;

	i = 0;
	t = "%";
	flags->length = ft_strlen(t);
	flags->percent = 1;
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
	if (flags->minus == 0 && flags->zero == 0)
		ft_printf_s1(flags, t, i);
	if (flags->minus == 1 && flags->zero == 0)
		ft_printf_s2(flags, t, i);
	if (flags->minus == 0 && flags->zero == 1)
		ft_printf_s1(flags, t, i);
}
