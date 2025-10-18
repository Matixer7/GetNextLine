/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumienn <mgumienn@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:25:24 by mgumienn          #+#    #+#             */
/*   Updated: 2025/10/18 15:38:11 by mgumienn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE 
# define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd);
void	load(int fd, char ***f_content);
int	ft_strchr(char *str, int c);

#endif