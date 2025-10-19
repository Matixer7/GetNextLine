/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:25:21 by mgumienn          #+#    #+#             */
/*   Updated: 2025/10/19 18:41:03 by mgumienn         ###   ########.fr       */
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
	size_t	rd;
	char	buffer[BUFFER_SIZE + 1];
	size_t	i;

	rd = read(fd, buffer, BUFFER_SIZE);
	if (rd <= 0)
		return (NULL);
	buffer[rd] = '\0';
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		*line = ft_strjoin(*line, buffer[i++]);
	if (buffer[i] == '\n')
	{
		*line = ft_strjoin(*line, buffer[i++]);
		if (buffer[i])
		{
			if (*f_content)
				free(*f_content);
			*f_content = ft_strdup(&buffer[i]);
		}
		return (*line);
	}
	return (ft_read(fd, f_content, line));
}

char	*get_next_line(int fd)
{
	static char	*f_content;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (f_content && !ft_strchr(f_content, '\n'))
	{
		line = ft_strdup(f_content);
		free(f_content);
		f_content = NULL;
	}
	if(f_content && ft_strchr(f_content, '\n') && !line)
		ft_trim(&line, &f_content);
	if (f_content && line)
		return (line);
	if (!f_content)
		ft_read(fd, &f_content, &line);
	return (line);
}

#include "stdio.h"
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *line;
	
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}