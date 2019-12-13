/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:12:42 by rvegas-j          #+#    #+#             */
/*   Updated: 2019/11/11 17:28:34 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int		i;
	char	*ptr;

	ptr = (char*)malloc(size * count);
	i = 0;
	if (!((char*)malloc(size * count)))
		return (0);
	while (ptr[i] != '\0')
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
