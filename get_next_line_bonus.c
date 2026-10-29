/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:24:09 by keblanch          #+#    #+#             */
/*   Updated: 2026/10/29 12:18:59 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

static void	free_leftover_and_buf(char **leftover, char **buf)
{
	if (buf)
		free(*buf);
	if (leftover)
	{
		free(*leftover);
		*leftover = NULL;
	}
}

static int	concat(char **dest, char *src)
{
	size_t	dest_len;
	size_t	src_len;
	char	*t;

	if (!src)
		return (0);
	dest_len = 0;
	if (*dest)
		dest_len = gnl_strlen(*dest, '\0');
	src_len = gnl_strlen(src, '\0');
	t = ft_calloc(dest_len + src_len + 1, sizeof(char));
	if (!t)
		return (0);
	ft_memcpy(t, (*dest), dest_len);
	ft_memcpy(t + dest_len, src, src_len);
	free((*dest));
	(*dest) = t;
	return (1);
}

static int	read_from_file(int fd, char **leftover)
{
	char	*buf;
	int		bytes_read;
	int		has_concat;

	has_concat = 1;
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
	{
		free_leftover_and_buf(leftover, &buf);
		return (0);
	}
	bytes_read = 1;
	while (bytes_read > 0 && !check_for_nl(*leftover) && has_concat)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read >= 0)
		{
			buf[bytes_read] = '\0';
			has_concat = concat(leftover, buf);
		}
	}
	if (!has_concat || bytes_read < 0)
		free_leftover_and_buf(leftover, NULL);
	free(buf);
	return (bytes_read);
}

static char	*extract_line(char *leftover)
{
	char	*ret;
	size_t	i;
	size_t	leftover_len;

	if (!leftover[0])
		return (NULL);
	i = gnl_strlen(leftover, '\n');
	if (leftover[i] == '\n')
		++i;
	ret = gnl_substr(leftover, i);
	if (!ret)
		return (NULL);
	leftover_len = gnl_strlen(leftover + i, '\0');
	ft_memcpy(leftover, leftover + i, leftover_len);
	leftover[leftover_len] = '\0';
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*leftover[MAX_FD];
	int			bytes_read;

	if (BUFFER_SIZE < 1 || fd < 0 || fd >= MAX_FD)
	{
		if (fd >= 0 && fd < MAX_FD)
			free_leftover_and_buf(leftover + fd, NULL);
		return (NULL);
	}
	bytes_read = read_from_file(fd, leftover + fd);
	if (leftover[fd] == NULL)
		return (NULL);
	ret = extract_line(leftover[fd]);
	if (!ret && !bytes_read)
	{
		free_leftover_and_buf(leftover + fd, NULL);
		return (NULL);
	}
	return (ret);
}
