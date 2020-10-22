#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"
#include <string.h>

// void	ft_putstr(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		write(1, &str[i], 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// }

// int		main(int argc, char **argv)
// {
// 	char	*line;
// 	int		i;
// 	int		j;
// 	int		ret;
// 	int		file;
// 	int		fd;

// 	i = 0;
// 	if (argc == 2)
// 		j = 1;
// 	else
// 		j = atoi(argv[2]);
// 	// stdin
// 	fd = open((argv[1]), O_RDONLY);
// 	while (i < j)
// 	{
// 		line = (char *)malloc(sizeof(*line) * 1);
// 		if (!line)
// 			return (0);
// 		ret = get_next_line(fd, &line);
// 		printf("stdin:	|%s|\n", line);
// 		i++;
// 	}
// 	// big.txt
// 	while (i < j)
// 	{
// 		line = (char *)malloc(sizeof(*line) * 1);
// 		if (!line)
// 			return (0);
// 		ret = get_next_line(open("big.txt", O_RDONLY), &line);
// 		printf("normal:	|%s|\n", line);
// 		free(line);
// 		i++;
// 	}
// 	// sample.txt
// 	while (i < j)
// 	{
// 		line = (char *)malloc(sizeof(*line) * 1);
// 		if (!line)
// 			return (0);
// 		ret = get_next_line(open("sample.txt", O_RDONLY), &line);
// 		printf("get_next_line return:	|%i|\n", ret);
// 		printf("normal:	|%s|\n", line);
// 		i++;
// 	}
// 	// null.txt
// 	while (i < j)
// 	{
// 		line = (char *)malloc(sizeof(*line) * 1);
// 		if (!line)
// 			return (0);
// 		ret = get_next_line(open("null.txt", O_RDONLY), &line);
// 		printf("get_next_line return:	|%i|\n", ret);
// 		printf("normal:	|%s|\n", line);
// 		i++;
// 	}
// 	return (0);
// }

// int		not_all_done(int *ret, int argc)
// {
// 	int		i;
// 	i = 0;
// 	while (i + 1 < argc)
// 	{
// 		if (ret[i] != 0)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// int		main(int argc, char **argv)
// {
// 	int		i;
// 	int		fd[argc - 1];
// 	int		ret[argc - 1];
// 	char	*line;

// 	line = NULL;
// 	i = 0;
// 	while (i + 1 < argc)
// 	{
// 		fd[i] = open(argv[i + 1], O_RDONLY);
// 		ret[i] = 1;
// 		i++;
// 	}
// 	while (not_all_done(ret, argc))
// 	{
// 		i = 0;
// 		while (i + 1 < argc)
// 		{
// 			if (ret[i] != 0)
// 			{
// 				ret[i] = get_next_line(fd[i], &line);
// 				printf("OUT _%d_%d_%s_\n", fd[i], ret[i], line);
// 				if (!ret[i])
// 					close(fd[i]);
// 			}
// 			i++;
// 		}
// 	}
// 	free(line);
// 	return (0);
// }

int main(void)
{
    const int fd = open("example_text.txt", O_RDONLY);
    char *line = NULL;
    int ret;


    ret = get_next_line(fd, &line);
    free(line);
    ret = get_next_line(fd, &line);
    free(line);
    ret = get_next_line(fd, &line);
    free(line);
    ret = get_next_line(fd, &line);
    free(line);
    close(fd);
    ret = get_next_line(fd, &line); // memory is still allocated in the static buffer here
    // free(line);
    sleep(100);
    // https://github.com/VictorTennekes/get_next_line/blob/e66f0f40b8760e49fc179a6f27632c807dcbe732/get_next_line.c#L63
}