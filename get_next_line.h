/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 10:07:54 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/28 16:46:32 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_read
{
	int				eof;
}					t_read;

size_t				ft_strlen(const char *s);
size_t				ft_strlen_new(const char *s);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strchr(const char *s, int c);
char				*ft_substr(char *s, unsigned int start, size_t len);
int					get_next_line(int fd, char **line);
int					get_line(char **get, char **line, int c);
char				*ft_strdup(const char *s1);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_strrchr(const char *s, int c);

#endif
