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

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = (void *)malloc(n * size);
	if (!ptr)
		return (0);
	while (i < n)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (!str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	while (i < len && s[start] != 0)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;
	size_t	i;
	size_t	j;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	i = 0;
	while (i <= ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (j <= ft_strlen(s2))
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strchr(const char *str, int c)
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
