/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 10:07:26 by vtenneke       #+#    #+#                */
/*   Updated: 2019/12/10 17:55:00 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	if (!(src))
		return (0);
	i = 0;
	while (src[i] && i < (int)dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

int		get_line(char **res, char **line, int c)
{
	char	*tmp;

	*line = ft_substr(*res, 0, ft_strchr(*res, c) + ((c == '\0') ? 1 : -1));
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
	static char	*res[1024];
	char		*tmp;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		readc;

	if (BUFFER_SIZE < 0 || read(fd, 0, 0) == -1)
		return (-1);
	if (!res[fd])
		res[fd] = ft_strdup("");
	readc = 1;
	while (readc && !ft_strchr(res[fd], '\n'))
	{
		readc = read(fd, buf, BUFFER_SIZE);
		if (readc == -1)
			return (-1);
		buf[readc] = 0;
		tmp = ft_strjoin(res[fd], buf);
		free(res[fd]);
		res[fd] = tmp;
	}
	if (readc)
		return (get_line(&res[fd], line, '\n'));
	else
		return (get_line(&res[fd], line, '\0'));
}
