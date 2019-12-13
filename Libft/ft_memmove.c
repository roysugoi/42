/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:07:19 by rvegas-j          #+#    #+#             */
/*   Updated: 2019/11/10 20:06:12 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*str2;
	unsigned char	*str1;
	unsigned long	i;

	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	if ((str1 || str2))
	{
		i = 0;
		if (str2 < str1)
			while (++i <= n)
				str1[n - i] = str2[n - i];
		else
			while (n-- > 0)
				*(str1++) = *(str2++);
		return (dst);
	}
	else
		return (0);
}
