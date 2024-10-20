/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:46:45 by lsaumon           #+#    #+#             */
/*   Updated: 2024/10/21 01:02:31 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_gnlstrlen(const char *s);
char	*ft_gnlsubstr(char const *s, unsigned int start, size_t len);
size_t	ft_gnlstrlcpy(char *dst, const char *src, size_t size);
char	*ft_gnlstrchr(const char *s, int c);
void	*ft_gnlcalloc(size_t nmemb, size_t size);
char	*ft_gnlstrjoin(char *s1, char *s2);
void	*ft_gnlmemmove(void *dest, const void *src, size_t n);

#endif