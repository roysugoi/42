/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:53:25 by rvegas-j          #+#    #+#             */
/*   Updated: 2019/11/11 00:52:05 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*aux;
	unsigned long	i;
	unsigned long	len;

	i = 0;
	len = ft_strlen(s);
	if (!(aux = (char *)malloc(sizeof(*aux) * (len + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		aux[i] = s[i];
		i++;
	}
	aux[i] = '\0';
	return (aux);
}
