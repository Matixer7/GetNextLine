/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:16:47 by mgumienn          #+#    #+#             */
/*   Updated: 2025/10/24 18:25:44 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(ft_strlen(src) * sizeof(char) + 1);
	if (dup == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strchr(char *str, int c)
{
	if (c == 0 || !str)
		return (0);
	while (*str)
	{
		if (*str == (char) c)
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char c)
{
	char	*str;
	size_t	i;
	size_t	s1_len;

	i = 0;
	if (!s1)
	{
		str = malloc(2);
		if (!str)
			return (NULL);
		str[0] = c;
		return (str[1] = '\0', str);
	}
	s1_len = ft_strlen(s1);
	str = malloc(s1_len + 2);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	return (free(s1), str);
}

size_t	ft_strlcpy(char **dest, char *src, size_t size)
{
	size_t	i;
	size_t	src_size;

	i = 0;
	if (!src)
		return (0);
	src_size = ft_strlen(src);
	if (size > 0)
	{
		while (i < (size - 1) && src[i])
		{
			(*dest)[i] = src[i];
			i++;
		}
		(*dest)[i] = '\0';
	}
	return (src_size);
}
