#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <string.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		i;
	int		ret;
	int		file;

	i = 0;
	(void)argc;
	while (i < 18)
	{
		line = (char *)malloc(sizeof(*line) * 1);
		if (!line)
			return (0);
		ret = get_next_line(open((argv[1]), O_RDONLY), &line);
		printf("stdin:	|%s|\n", line);
		free(line);
		i++;
	}
	// big.txt
	while (i < 18)
	{
		line = (char *)malloc(sizeof(*line) * 1);
		if (!line)
			return (0);
		ret = get_next_line(open("big.txt", O_RDONLY), &line);
		printf("normal:	|%s|\n", line);
		free(line);
		i++;
	}
	// sample.txt
	while (i < 18)
	{
		line = (char *)malloc(sizeof(*line) * 1);
		if (!line)
			return (0);
		ret = get_next_line(open("sample.txt", O_RDONLY), &line);
		printf("normal:	|%s|\n", line);
		free(line);
		i++;
	}
	return (0);
}
