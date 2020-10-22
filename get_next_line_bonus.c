/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 10:07:26 by vtenneke      #+#    #+#                 */
/*   Updated: 2019/12/18 09:49:46 by vtenneke      ########   odam.nl         */
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
	if (!*line)
		return (-1);
	if (c == '\0')
	{
		free(*res);
		*res = NULL;
		return (0);
	}
	tmp = ft_substr(*res, ft_strchr(*res, c),
		ft_strrchr(*res, '\0') - ft_strchr(*res, c));
	if (!tmp)
		return (-1);
	free(*res);
	*res = tmp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*res[INT_MAX];
	char		buf[BUFFER_SIZE + 1];
	ssize_t		readc;

	if (line)
		*line = NULL;
	if (BUFFER_SIZE < 0 || !line || read(fd, 0, 0) == -1)
	{
		free(res[fd]);
		return (GNL_ERROR);
	}
	if (!res[fd])
		res[fd] = ft_strdup("");
	readc = 1;
	while (readc && !ft_strchr(res[fd], '\n'))
	{
		readc = read(fd, buf, BUFFER_SIZE);
		if (readc == -1)
			return (-1);
		buf[readc] = 0;
		res[fd] = ft_strjoin(res[fd], buf);
		if (!res[fd])
			return (-1);
	}
	return (get_line(&res[fd], line, ((readc) ? '\n' : '\0')));
}
