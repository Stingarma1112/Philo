/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:46:51 by lsaumon           #+#    #+#             */
/*   Updated: 2024/03/08 03:32:22 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	i;

	if (!size && !dst)
		return (0);
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	dest_len = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && dest_len + 1 < size)
	{
		dst[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dst[dest_len] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
