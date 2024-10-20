/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:40:59 by lsaumon           #+#    #+#             */
/*   Updated: 2024/03/08 03:31:18 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tableau;

	if (!nmemb || !size)
		return (malloc (0));
	if ((nmemb * size) / size != nmemb)
		return (NULL);
	tableau = malloc(nmemb * size);
	if (!tableau)
		return (NULL);
	ft_memset(tableau, 0, nmemb * size);
	return (tableau);
}
