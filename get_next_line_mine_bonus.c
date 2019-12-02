/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_mine_bonus.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/29 12:50:36 by vtenneke       #+#    #+#                */
/*   Updated: 2019/12/02 15:57:16 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_file	*get_file_data(t_file *data, int fd_in)
{
	t_file			*file;

	file = (t_file*)malloc(sizeof(t_file));
	while (data->next)
	{
		if (data->fd == fd_in)
			return (data);
		data = data->next;
	}
	if (data->fd == fd_in)
		return (data);
	data->next = file;
	file->readc = 0;
	file->fd = fd_in;
	file->next = NULL;
	return (file);
}

int		get_next_line(int fd, char **line)
{
	static t_file	data;
	t_file			*file_data;

	file_data = get_file_data(&data, fd);
	if (!file_data->res)
	{
		file_data->res = (char*)malloc(sizeof(char));
		file_data->res[0] = '\0';
	}
	if (read(fd, 0, 0) == -1)
		return (-1);
	get_line(file_data);
	if (readc)
		return (get_line(file_data, line, '\n'));
	else
		return (get_line(file_data, line, '\0'));
}
