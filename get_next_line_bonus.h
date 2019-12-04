/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 10:07:54 by vtenneke       #+#    #+#                */
/*   Updated: 2019/12/04 10:20:41 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# ifndef MAX_INT
#  define MAX_INT 2147483647
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
