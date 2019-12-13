/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roy <roy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:10:38 by rvegas-j          #+#    #+#             */
/*   Updated: 2019/12/12 14:38:04 by roy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	t_flags_init(t_flags *flags)
{
	flags->minus = 0;
	flags->zero = 0;
	flags->minwidth = 0;
	flags->asterisk1 = 0;
	flags->dot = 0;
	flags->maxwidth = 0;
	flags->asterisk2 = 0;
	flags->variable = 0;
}
