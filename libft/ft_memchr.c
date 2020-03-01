/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 22:26:06 by rvegas-j          #+#    #+#             */
/*   Updated: 2019/11/06 14:45:32 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char*)s)[i] == ((unsigned char)c))
			return (&((char*)s)[i]);
		i++;
	}
	return (NULL);
}
