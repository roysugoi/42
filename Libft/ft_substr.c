/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:52:56 by rvegas-j          #+#    #+#             */
/*   Updated: 2019/11/11 19:19:48 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*aux;
	unsigned long	count;
	unsigned long	size;

	count = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	if (!(aux = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (count < len)
	{
		aux[count] = s[start + count];
		count++;
	}
	aux[count] = '\0';
	return (aux);
}
