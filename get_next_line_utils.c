/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:24:56 by keblanch          #+#    #+#             */
/*   Updated: 2026/10/27 15:05:35 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <limits.h>

size_t	check_for_nl(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		++i;
	}
	return (0);
}

size_t	gnl_strlen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!src)
		return (dest);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		++i;
	}
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*s;
	size_t			i;

	s = 0;
	i = 0;
	if (nmemb != 0 && (((size_t) - 1) / nmemb < size))
		return (s);
	s = malloc(nmemb * size);
	if (!s)
		return (s);
	while (i < nmemb * size)
	{
		s[i] = 0;
		++i;
	}
	return ((void *)s);
}

char	*gnl_substr(const char *s, size_t len)
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	while (i < len && s[i])
	{
		ret[i] = s[i];
		++i;
	}
	ret[len] = '\0';
	return (ret);
}
