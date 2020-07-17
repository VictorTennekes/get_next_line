/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 10:07:39 by vtenneke      #+#    #+#                 */
/*   Updated: 2020/01/23 10:51:02 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <errno.h>

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*res;
	int		l1;
	int		l2;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strchr_gnl(s1, '\0');
	l2 = ft_strchr_gnl(s2, '\0');
	res = (char*)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!res)
		return (NULL);
	res[l1 + l2] = '\0';
	i = 0;
	while (i < l1 || i < l2)
	{
		if (i < l1)
			res[i] = s1[i];
		if (i < l2)
			res[i + l1] = s2[i];
		i++;
	}
	return (res);
}

int		ft_strrchr_gnl(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
		i++;
	if (!c)
		return (i);
	while (i >= 0)
	{
		if (s[i] == c)
			return (i);
		i--;
	}
	return (-1);
}

int		ft_strchr_gnl(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i + 1);
		i++;
	}
	if (!c)
		return (i);
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (i < start)
		return (ft_strdup(""));
	sub = (char*)malloc(sizeof(char) *
		((i - start < len) ? i - start : len) + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, ((i - start < len) ? i - start : len) + 1);
	return (sub);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	str = (char*)malloc(len + 1);
	if (!(str))
		ENOMEM;
	else
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (0);
}
