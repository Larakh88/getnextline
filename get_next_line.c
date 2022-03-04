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

char	*ft_read(int fd, char *readline, char *buff)
{
	ssize_t	byte;

	byte = 1;
	while (ft_strchr(readline, '\n') == 0 && byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[byte] = '\0';
		readline = ft_strjoin(readline, buff);
	}
	return (readline);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*readline;
	size_t		i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	readline = ft_read(fd, readline, buff);
	if (readline == 0)
		return (NULL);
	while (readline[i] != '\n' && readline[i] != 0)
		i++;
	line = ft_substr(readline, 0, i + 1);
	readline = ft_substr(readline, i + 1, ft_strlen(readline) - i - 1);
	free (buff);
	return (line);
}
