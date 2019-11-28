/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_mine.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/28 16:38:00 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/28 16:56:10 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
** 1 : A line has been read
** 0 : EOF has been reached
** -1 : An error happened
*/

int		get_line(char **res, char **line, t_read *read_data)
{
	char	*tmp;

	*line = ft_substr(*res, 0, ft_strchr(*res, read_data->eof)
		- ((read_data->eof == '\0') ? -1 : 1));
	if (read_data->eof == '\0')
	{
		free(*res);
		*res = NULL;
		return (0);
	}
	tmp = ft_substr(*res, ft_strchr(*res, read_data->eof),
		ft_strrchr(*res, '\0') - ft_strchr(*res, read_data->eof));
	free(*res);
	*res = tmp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*res;
	char		*tmp;
	char		buf[BUFFER_SIZE + 1];
	size_t		readc;
	t_read		read_data;

	read_data.eof = '\0';
	if (!res)
	{
		res = (char*)malloc(sizeof(char));
		res[0] = '\0';
	}
	if (read(fd, 0, 0) == -1)
		return (-1);
	readc = 1;
	while (readc && !ft_strchr(res, '\n'))
	{
		readc = read(fd, buf, BUFFER_SIZE);
		buf[readc] = '\0';
		tmp = ft_strjoin(res, buf);
		free(res);
		res = tmp;
	}
	if (ft_strchr(res, '\n') == 0)
		read_data.eof = '\n';
	return (get_line(&res, line, &read_data));
}
