/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 10:07:26 by vtenneke       #+#    #+#                */
/*   Updated: 2019/12/02 11:36:00 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
** 1 : A line has been read
** 0 : EOF has been reached
** -1 : An error happened
*/

// t_file		*check_fd(t_file **data, int fd)
// {
// 	t_file		*new_file;
// 	t_file		*new_data;

// 	new_data = *data;
// 	while (new_data && new_data->next)
// 	{
// 		if (new_data->fd == fd)
// 			return (new_data);
// 		new_data = new_data->next;
// 	}
// 	if (new_data && new_data->fd == fd)
// 		return (new_data);
// 	new_file = (t_file*)malloc(sizeof(t_file));
// 	if (data)
// 		new_data->next = new_file;
// 	else
// 		*data = new_file;
// 	new_file->readc = 0;
// 	new_file->fd = fd;
// 	new_file->next = NULL;
// 	new_file->res = (char*)malloc(sizeof(char));
// 	new_file->res[0] = '\0';
// 	return (new_file);
// }

int		get_line(char **res, char **line, int c)
{
	char	*tmp;

	*line = ft_substr(*res, 0, ft_strchr(*res, c) - ((c == '\0') ? -1 : +1));
	if (c == '\0')
	{
		free(*res);
		*res = NULL;
		return (0);
	}
	tmp = ft_substr(*res, ft_strchr(*res, c),
		ft_strrchr(*res, '\0') - ft_strchr(*res, c));
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
	// t_file		*data;

	// check_fd(&data, fd);
	if (!line)
		return (-1);
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
		buf[readc] = 0;
		tmp = ft_strjoin(res, buf);
		free(res);
		res = tmp;
	}
	if (readc)
		return (get_line(&res, line, '\n'));
	else
		return (get_line(&res, line, '\0'));
}
