/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 10:07:26 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/01/23 10:49:20 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		return (GNL_ERROR);
	if (c == '\0')
	{
		free(*res);
		*res = NULL;
		return (GNL_EOF);
	}
	tmp = ft_substr(*res, ft_strchr(*res, c),
		ft_strrchr(*res, '\0') - ft_strchr(*res, c));
	if (!tmp)
		return (GNL_ERROR);
	free(*res);
	*res = tmp;
	return (GNL_SUCCES);
}

int		get_next_line(int fd, char **line)
{
	static char	*res = NULL;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		readc;

	if (line)
		*line = NULL;
	if (BUFFER_SIZE < 0 || !line || read(fd, 0, 0) == -1)
	{
		free(res);
		return (GNL_ERROR);
	}
	if (res == NULL)
		res = ft_strdup("");
	readc = 1;
	while (readc && !ft_strchr(res, '\n'))
	{
		readc = read(fd, buf, BUFFER_SIZE);
		if (readc == -1)
			return (GNL_ERROR);
		buf[readc] = 0;
		res = ft_strjoin(res, buf);
		if (!res)
			return (GNL_ERROR);
	}
	return (get_line(&res, line, ((readc) ? '\n' : '\0')));
}
