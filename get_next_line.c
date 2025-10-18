/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:25:21 by mgumienn          #+#    #+#             */
/*   Updated: 2025/10/18 15:37:42 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	**f_content;
	char		*line;

	if(!f_content)
		f_content = malloc(sizeof(char*) * 2);
	if (!ft_strchr(f_content[0], '\0'))
		load(fd, &f_content);
	line = f_content[0];
	if (line == "")
		return (NULL);
	f_content[0] = f_content[1];
	f_content[1] = "";
	return(line);
}

#include "stdio.h"
int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *line = get_next_line(fd);
	while (line)
	{
		printf("%s\n", line);
		//free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (0);
}
