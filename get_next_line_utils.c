/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 10:07:39 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/27 16:47:15 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <errno.h>

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0' || s[len] != '\n')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	k;

	k = 0;
	if (s1 == 0)
		return (NULL);
	i = ft_strchr(s1, '\n') + ft_strchr(s2, '\n');
	dest = (char*)malloc(i + 1);
	if (!(dest))
		return (NULL);
	while (*s1)
	{
		dest[k] = *s1;
		s1++;
		k++;
	}
	while (*s2)
	{
		dest[k] = *s2;
		s2++;
		k++;
	}
	dest[k] = '\0';
	return (dest);
}

int		ft_strchr(const char *s, int c)
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
		return (i - 1);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	tmp;
	char			*dest;

	i = 0;
	if (s == 0)
		return (NULL);
	tmp = ft_strlen(s);
	if (start > tmp)
		return (ft_strdup(""));
	dest = (char*)malloc(len + 1);
	if (!(dest))
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
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
