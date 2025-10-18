/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:16:47 by mgumienn          #+#    #+#             */
/*   Updated: 2025/10/18 15:37:46 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
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
	if (c == 0)
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
		return (ft_strjoin("", c));
	s1_len = ft_strlen(s1);
	if (s1_len != 0 && 1 > SIZE_MAX / s1_len)
		return (NULL);
	str = malloc(s1_len + 1 + 1);
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	return (str);
}

void	load(int fd, char ***f_content)
{
	int		rd;
	char	buffer[BUFFER_SIZE];
	size_t	i;

	i = 0;
	rd = read(fd, buffer, BUFFER_SIZE);
	if (!rd)
		return ;
	if (buffer[i] == '\0')
		*f_content[0] = ft_strjoin(*f_content[0], '\0');
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		*f_content[0] = ft_strjoin(*f_content[0], buffer[i]);
		i++;
	}
	if (buffer[i] == '\n')
	{
		if(buffer[i + 1])
			*f_content[1] = ft_strdup(&buffer[i + 1]);
		return ;
	}
	else if (ft_strchr(*f_content[0], '\0'))
		return ;
	else 
		load(fd, f_content);
}