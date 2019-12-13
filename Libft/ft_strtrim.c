/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:34:42 by rvegas-j          #+#    #+#             */
/*   Updated: 2019/11/16 20:55:18 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
​
static char    *ft_strncpy(char *dst, char *src, unsigned int n)
{
    unsigned int    i;
    ​
    i = 0;
    while (src[i] != 0 && i < n)
    {
        dst[i] = src[i];
        i++;
    }
    while (i < n)
    {
        dst[i] = 0;
        i++;
    }
    return (dst);
}
​
char        *ft_strtrim(const char *s1, const char *set)
{
    int        i;
    int        k;
    char    *s2;
    ​
    i = 0;
    if (s1 == 0)
        return (0);
    while (ft_strchr(set, s1[i]) != 0 && s1[i] != 0)
        i++;
    k = ft_strlen(s1) - i;
    if (k != 0)
    {
        while (ft_strchr(set, s1[k + i - 1]) != 0 && i < k - 1)
            k--;
    }
    if (!(s2 = (char *)malloc(sizeof(char) * (k + 1))))
        return (0);
    ft_strncpy(s2, &((char *)s1)[i], k);
    s2[k] = 0;
    return (s2);
}
