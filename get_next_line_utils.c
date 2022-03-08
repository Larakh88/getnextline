/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lel-khou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:03:57 by lel-khou          #+#    #+#             */
/*   Updated: 2022/02/17 12:00:15 by lel-khou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, ssize_t len)
{
	char	*str;
	ssize_t	i;

	i = 0;
	if (s == 0 || ft_strlen(s) == 0) 
		return (NULL);
	if (len == 0)
		len = 1;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
	{
		free (str);
		return (NULL);
	}
	while (i < len && s[start] != '\n')
	{
		str[i] = s[start];
		i++;
		start++;
	}
	if (s[start] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_leftstr(char *s, unsigned int start, ssize_t len)
{
	char	*str;
	ssize_t	i;

	i = 0;
	if (s == 0 || len <= 0)
	{
		free (s);
		return (NULL);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (i <= len && s[start] != 0)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	free (s);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str || !s1)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
		str[i++] = s2[j++];
	str[i] = 0;
	free (s1);
	return (str);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	if (str == 0)
		return (0);
	if (c == 0)
		return ((char *)(str + ft_strlen(str)));
	while (str[i] != 0)
	{
		if (str[i] != (char)c)
			i++;
		else
			return ((char *)(str + i));
	}
	return (0);
}
