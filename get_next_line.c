/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 10:07:26 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/27 16:47:44 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
** 1 : A line has been read
** 0 : EOF has been reached
** -1 : An error happened
*/
int		get_line(char **get, char **line, int c)
{
	char	*tmp;

	*line = ft_substr(*get, 0, ft_strchr(*get, c));
	if (c == '\0')
	{
		free(*get);
		return (0);
	}
	tmp = ft_substr(*get, ft_strchr(*get, c) + 1, ft_strlen(*get) - ft_strchr(*get, c));
	free(*get);
	*get = tmp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*get;
	char		*tmp;
	char		buf[BUFFER_SIZE];
	size_t		readc;

	readc = 1;
	if (!get)
	{
		get = (char*)malloc(sizeof(char));
		get[0] = '\0';
	}
	while (readc)
	{
		readc = read(fd, buf, BUFFER_SIZE - 1);
		buf[readc] = '\0';
		if (!readc)
			break ;
		tmp = ft_strjoin(get, buf);
		free(get);
		get = tmp;
	}
	if (readc)
		return (get_line(&get, line, '\n'));
	else
		return (get_line(&get, line, '\0'));
}
