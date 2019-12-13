/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvegas-j <rvegas-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:35:55 by rvegas-j          #+#    #+#             */
/*   Updated: 2019/11/25 17:39:39 by rvegas-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static int	ft_outputs(int bytesread, char **s, char **line)
{
	char	*temp1;
	char	*temp2;

	if (bytesread < 0)
		return (-1);
	if (!bytesread && !*s)
	{
		*line = ft_strdup("");
		return (0);
	}
	if ((temp1 = ft_strchr(*s, '\n')))
	{
		*temp1 = '\0';
		*line = ft_strdup(*s);
		temp2 = ft_strdup(++temp1);
		free(*s);
		*s = temp2;
	}
	else
	{
		*line = *s;
		*s = NULL;
		return (0);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*s[4096];
	int			bytesread;
	char		*temp;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((bytesread = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytesread] = '\0';
		if (s[fd] == '\0')
			s[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(s[fd], buffer);
			free(s[fd]);
			s[fd] = temp;
		}
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (ft_outputs(bytesread, &s[fd], line));
}
