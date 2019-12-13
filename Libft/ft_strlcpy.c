/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 15:46:31 by rvegas-j          #+#    #+#             */
/*   Updated: 2019/11/11 01:30:30 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	if (!dst && !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (size > 1 && *src)
	{
		*dst = *src;
		++src;
		++dst;
		++i;
		--size;
	}
	*dst = '\0';
	while (*dst || *src)
	{
		if (*src)
		{
			++src;
			++i;
		}
	}
	return (i);
}
