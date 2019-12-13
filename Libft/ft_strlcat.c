/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:06:48 by rvegas-j          #+#    #+#             */
/*   Updated: 2019/11/06 17:06:55 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	dstsize;
	unsigned long	srcsize;
	unsigned long	h;
	unsigned long	i;
	unsigned long	j;

	srcsize = 0;
	dstsize = 0;
	while (src[srcsize] != '\0')
		srcsize++;
	while (dst[dstsize] != '\0')
		dstsize++;
	if (size < dstsize)
		return (size + srcsize);
	i = 0;
	j = dstsize;
	h = size - dstsize;
	while (src[i] && h-- > 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (dstsize + srcsize);
}
