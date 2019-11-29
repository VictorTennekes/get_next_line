/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 10:07:54 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/29 12:59:17 by vtenneke      ########   odam.nl         */
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
int					check_fd(t_read *data);
void				ft_lstadd_back(t_read **alst, t_read *new);

#endif
