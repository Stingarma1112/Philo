/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:28:26 by lsaumon           #+#    #+#             */
/*   Updated: 2024/03/08 03:32:30 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*chaine;

	i = 0;
	if (!s)
		return (NULL);
	chaine = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!chaine)
		return (NULL);
	while (s[i])
	{
		chaine[i] = f(i, s[i]);
		i++;
	}
	chaine[ft_strlen(s)] = '\0';
	return (chaine);
}
