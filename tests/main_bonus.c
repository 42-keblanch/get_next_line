/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:59:43 by keblanch          #+#    #+#             */
/*   Updated: 2026/10/29 14:00:30 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	finished_reading(int reading[1024], int *fds, int nb_fds)
{
	for (int i = 0; i < nb_fds; i++)
	{
		if (reading[fds[i]])
			return (0);
	}
	return (1);
}

void	read_stdin()
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(0);
	}
	close(0);
}

int	main(int argc, char **argv)
{
	char	*line;
	int		reading[1024];
	int		*fd;

	if (argc == 1)
	{
		read_stdin();
		return (0);
	}

	fd = malloc((argc - 1) * sizeof(int));
	for (int i = 0; i < argc - 1; i++)
	{
		fd[i] = open(argv[i + 1], O_RDONLY);
		reading[fd[i]] = 1;
		if (fd[i] < 0)
			reading[fd[i]] = 0;
	}
	while (!finished_reading(reading, fd, argc - 1))
	{
		for (int i = 0; i < argc - 1; i++)
		{
			if (reading[fd[i]])
			{
				line = get_next_line(fd[i]);
				if (line)
				{
					printf("[%i]%s", fd[i], line);
					free(line);
				}
				else
					reading[fd[i]] = 0;
			}
		}
	}
	for (int i = 0; i < argc - 1; i++)
		line = get_next_line(fd[i]);
	for (int i = 0; i < argc - 1; i++)
		close(fd[i]);
	free(fd);

	return (0);
}
