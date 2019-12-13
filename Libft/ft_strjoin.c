/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:21:50 by rvegas-j          #+#    #+#             */
/*   Updated: 2019/11/11 20:58:21 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*aux;
	int		k;

	k = 0;
	if (s1 == '\0')
		return (0);
	if (!(aux = (char*)malloc(sizeof(*aux) * (ft_strlen(s1) +
		ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1 != '\0')
	{
		aux[k] = *s1;
		k++;
		s1++;
	}
	while (*s2 != '\0')
	{
		aux[k] = *s2;
		k++;
		s2++;
	}
	aux[k] = '\0';
	return (aux);
}
