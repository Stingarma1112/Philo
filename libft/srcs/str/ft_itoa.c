/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:19:13 by lsaumon           #+#    #+#             */
/*   Updated: 2024/03/08 03:32:07 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_len_itoa(int nb)
{
	int	i;

	i = 0;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		negatif;
	char	*tableau;

	negatif = 0;
	if (n < 0)
	{
		negatif = 1;
		n *= -1;
	}
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tableau = ft_calloc(ft_len_itoa(n) + negatif + 1, sizeof(char));
	if (!tableau)
		return (NULL);
	while (n)
	{
		tableau[ft_len_itoa(n) + negatif - 1] = (n % 10) + 48;
		n /= 10;
	}
	if (negatif == 1)
		tableau[0] = '-';
	return (tableau);
}
