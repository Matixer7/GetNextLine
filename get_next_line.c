/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:25:21 by mgumienn          #+#    #+#             */
/*   Updated: 2025/10/19 14:57:16 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_trim(char **line, char **f_content)
{
	int	i;

	i = 0;
	while ((*f_content)[i] != '\n')
		i++;
	ft_strlcpy(line, *f_content, i + 2);
	*f_content = ft_strdup(&(*f_content)[i +1]);
}

char	*ft_read(int fd, char **f_content, char **line)
{
	int		rd;
	char	buffer[BUFFER_SIZE];
	int		i;

	rd = read(fd, buffer, BUFFER_SIZE);
	if (!rd)
		return (NULL);
	i = 0;
	while(buffer[i] != '\n' && buffer[i] != '\0')
		*line = ft_strjoin(*line, buffer[i++]);
	if (buffer[i] == '\n')
		*line = ft_strjoin(*line, buffer[i++]);
	if (buffer[i])
		*f_content = ft_strdup(&buffer[i]);
	if (ft_strchr(*line, '\n'))
		return (*line);
	else
		ft_read(fd, f_content, line);
}

char	*get_next_line(int fd)
{
	static char	*f_content;
	char		*line;

	line = NULL;
	if (f_content && !ft_strchr(f_content, '\n'))
	{
		line = f_content;
		f_content = NULL;
	}
	if (!f_content)
		ft_read(fd, &f_content, &line);
	if (ft_strchr(f_content, '\n') && !line)
		ft_trim(&line, &f_content);
	if (!line && !ft_strchr(f_content, '\n'))
		line = f_content;
	return (line);
}

#include "stdio.h"
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		//free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}
