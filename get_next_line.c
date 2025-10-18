/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:25:21 by mgumienn          #+#    #+#             */
/*   Updated: 2025/10/18 14:39:39 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	**f_content;
	char		*line;

	if(!f_content)
		f_content = malloc(sizeof(char*) * 2);
	load(fd, &f_content);
	line = f_content[0];
	if (line == NULL)
		free(f_content);
	f_content[0] = f_content[1];
	f_content[1] = "";
	return(line);
}

#include "stdio.h"
int main()
{
	int fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}
