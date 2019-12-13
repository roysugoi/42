/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 00:27:49 by rvegas-j          #+#    #+#             */
/*   Updated: 2019/11/15 21:12:02 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_numoflines(char const *s1, char c)
{
	int	lines;
	int	comp;

	lines = 0;
	comp = 0;
	if (*s1 == '\0')
		return (0);
	while (*s1 != '\0')
	{
		if (*s1 == c)
			comp = 0;
		else if (comp == 0)
		{
			comp = 1;
			lines++;
		}
		s1++;
	}
	return (lines);
}

static int		ft_numofchars(char const *s2, char c, int i)
{
	int	lenght;

	lenght = 0;
	while (s2[i] != c && s2[i] != '\0')
	{
		lenght++;
		i++;
	}
	return (lenght);
}

static char		**ft_array(char const *s, char **dst, char c, int l)
{
	int	i;
	int	y;
	int	k;

	i = 0;
	y = 0;
	while (s[i] != '\0' && y < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (!(dst[y] = (char *)malloc(sizeof(char) *
		ft_numofchars(s, c, i) + 1)))
			return (NULL);
		while (s[i] != '\0' && s[i] != c)
			dst[y][k++] = s[i++];
		dst[y][k] = '\0';
		y++;
	}
	dst[y] = 0;
	return (dst);
}

char			**ft_split(char const *s, char c)
{
	char	**dst;
	int		n;

	if (s == NULL)
		return (NULL);
	n = ft_numoflines(s, c);
	if (!(dst = (char **)malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	return (ft_array(s, dst, c, n));
}
