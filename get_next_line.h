/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 10:07:54 by vtenneke       #+#    #+#                */
/*   Updated: 2019/12/02 16:14:19 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_file
{
	char			*res;
	int				readc;
	int				fd;
	struct s_file	*next;
}					t_file;

int					get_next_line(int fd, char **line);
int					get_line(char **res, char **line, int c);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strrchr(const char *s, int c);
int					ft_strchr(const char *s, int c);
char				*ft_substr(char *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);

#endif
