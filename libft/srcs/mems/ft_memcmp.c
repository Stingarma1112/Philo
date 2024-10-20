/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:42:47 by lsaumon           #+#    #+#             */
/*   Updated: 2024/03/08 03:31:23 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*j1;
	unsigned char	*j2;

	i = 0;
	j1 = (unsigned char *)s1;
	j2 = (unsigned char *)s2;
	while (i < n)
	{
		if (j1[i] != j2[i])
			return ((int)j1[i] - (int)j2[i]);
		i++;
	}
	return (0);
}
