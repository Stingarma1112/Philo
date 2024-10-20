/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:47:29 by lsaumon           #+#    #+#             */
/*   Updated: 2024/03/08 03:32:36 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		j;

	if (!big && !len)
		return (NULL);
	if (ft_strlen(little) < 1)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && i + j < len)
		{
			if (big [i + j] == little[j])
			{
				if (little[j + 1] == '\0')
					return ((char *)&big[i]);
			}
			else
				break ;
			j++;
		}
		i++;
	}
	return (0);
}
