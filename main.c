/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: vtenneke <vtenneke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 16:14:27 by vtenneke       #+#    #+#                */
/*   Updated: 2019/11/27 16:16:56 by vtenneke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	close(fd);
	return (0);
}
