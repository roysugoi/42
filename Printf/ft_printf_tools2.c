/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roy <roy@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:44:55 by roy               #+#    #+#             */
/*   Updated: 2020/02/18 00:31:42 by roy              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int					i;
	unsigned long long	n;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (n);
}

int		ft_atoi_counter(int i)
{
	int j;

	j = 0;
	while (i / 10 >= 1)
		j++;
	j++;
	return (j);
}

size_t    ft_strlen(const char *str)
{
    int    size;
    
    size = 0;
    while (str[size] != '\0')
    {
        size += 1;
    }
    return (size);
}

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
