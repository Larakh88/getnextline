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
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*readline;
	ssize_t		byte;
	static size_t	i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buff = malloc (sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	while (ft_strchr(readline, '\n') == 0 && byte != 0)
	{
		byte = read(fd, buff, BUFFER_SIZE);
		if (byte < 0)
			return (0);
		readline = ft_strjoin(readline, buff);
	}
	while (readline[i] != '\n' && readline[i] != 0)
		i++;
	line = ft_substr(readline, i - i, i);
	free (buff);
	return (line);
}

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	
	fd1 = open("test.txt", O_RDONLY);

	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd1);

	return (0);
}
