/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_vars1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roy <roy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:43:42 by roy               #+#    #+#             */
/*   Updated: 2020/02/16 02:09:08 by roy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* int	ft_printf_c(const char *s, t_flags *flags)
{

}
*/
void	ft_printf_s(t_flags *flags)
{
	ft_putstr_fd(va_arg(flags->valist, char*), flags);
}

/*int	ft_printf_p(const char *s, t_flags *flags)
{
	
}

int	ft_printf_d(const char *s, t_flags *flags)
{
	
}

int	ft_printf_i(const char *s, t_flags *flags)
{
	
}
*/