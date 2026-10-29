/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keblanch <keblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 11:23:20 by keblanch          #+#    #+#             */
/*   Updated: 2026/10/29 12:06:59 by keblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif
# define MAX_FD 1024
# include <stddef.h>

char	*get_next_line(int fd);
size_t	check_for_nl(char *s);
size_t	gnl_strlen(char *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*gnl_substr(const char *s, size_t len);

#endif
