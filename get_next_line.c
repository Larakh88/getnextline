/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:03:32 by lel-khou          #+#    #+#             */
/*   Updated: 2022/02/16 11:44:31 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *readline)
{
	char	*buff;
	ssize_t	byte;

	byte = 1;
	buff = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
			break;
		buff[byte] = '\0';
		readline = ft_strjoin(readline, buff);
		if (!readline)
		{
			free (buff);
			return (NULL);
		}
		if (ft_strchr(readline, '\n'))
			break;
	}
	free (buff);
	return (readline);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*readline;
	size_t		i;

	i = 0;
	readline = ft_read(fd, readline);
	if (!readline)
		return (NULL);
	while (readline[i] != '\n' && readline[i] != '\0')
		i++;
	line = ft_substr(readline, 0, i);
	readline = ft_leftstr(readline, i + 1, ft_strlen(readline) - i);
	return (line);
}
