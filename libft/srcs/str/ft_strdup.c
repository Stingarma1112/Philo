/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:31:19 by lsaumon           #+#    #+#             */
/*   Updated: 2024/03/08 03:32:14 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*tableau;
	int		i;

	i = 0;
	tableau = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!tableau)
		return (NULL);
	while (s[i] != '\0')
	{
		tableau[i] = s[i];
		i++;
	}
	return (tableau);
}
