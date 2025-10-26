/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:25:21 by mgumienn          #+#    #+#             */
/*   Updated: 2025/10/26 13:38:56 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_trim(char **line, char **f_content)
{
	size_t	i;
	char	*new_content;

	i = 0;
	while ((*f_content)[i] != '\n')
		i++;
	*line = malloc(i + 2);
	if (!*line)
		return ;
	ft_strlcpy(line, *f_content, i + 2);
	if ((*f_content)[i + 1])
	{
		new_content = ft_strdup(&(*f_content)[i + 1]);
		free(*f_content);
		*f_content = new_content;
	}
	else
	{
		free(*f_content);
		*f_content = NULL;
	}
}

char	*ft_read(int fd, char **f_content, char **line)
{
	long	rd;
	char	*buffer;
	size_t	i;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(buffer), NULL);
	rd = read(fd, buffer, BUFFER_SIZE);
	if (rd <= 0 || !buffer)
		return (free(buffer), NULL);
	buffer[rd] = '\0';
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		*line = ft_strjoin(*line, buffer[i++]);
	if (buffer[i] && buffer[i] == '\n')
	{
		*line = ft_strjoin(*line, buffer[i++]);
		if (*f_content)
			free(*f_content);
		if (buffer[i])
			*f_content = ft_strdup(&buffer[i]);
		return (free(buffer), *line);
	}
	return (free(buffer), ft_read(fd, f_content, line));
}

char	*get_next_line(int fd)
{
	static char	*f_content[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (f_content[fd] && !ft_strchr(f_content[fd], '\n'))
	{
		line = ft_strdup(f_content[fd]);
		free(f_content[fd]);
		f_content[fd] = NULL;
	}
	if (f_content[fd] && ft_strchr(f_content[fd], '\n') && !line)
		ft_trim(&line, &f_content[fd]);
	if (f_content[fd] && line)
		return (line);
	if (!f_content[fd])
		ft_read(fd, &f_content[fd], &line);
	if (line == NULL && f_content[fd])
		free(f_content[fd]);
	return (line);
}
