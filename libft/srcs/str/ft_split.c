/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:13:19 by lsaumon           #+#    #+#             */
/*   Updated: 2024/03/08 03:32:10 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	ft_count_words(char const *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i] != '\0')
		{
			words++;
			while (str[i] && str[i] != sep)
				i++;
		}
	}
	return (words);
}

static int	ft_subcpy(char *str, char **tab, size_t len, size_t index)
{
	tab[index] = ft_substr(str, 0, len);
	if (!tab[index])
	{
		while (index > 0)
		{
			index--;
			free(tab[index]);
		}
		free(tab);
		return (0);
	}
	return (1);
}

static char	**ft_split_tab(char *str, char sep)
{
	char	**tab;
	size_t	i;
	size_t	j;
	int		k;

	i = 0;
	k = 0;
	tab = ft_calloc(ft_count_words(str, sep) + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	while (str[i] && k < ft_count_words(str, sep))
	{
		while (str[i] && str[i] == sep)
			i++;
		j = i;
		while (str[i] && str[i] != sep)
			i++;
		if (i != j && !ft_subcpy(str + j, tab, i - j, k++))
			return (NULL);
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (NULL);
	return (ft_split_tab((char *)s, c));
}
