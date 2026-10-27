#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	if (fd < 0)
		return (fd);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
