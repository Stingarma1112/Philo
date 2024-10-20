/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:17:17 by lsaumon           #+#    #+#             */
/*   Updated: 2024/03/08 03:31:09 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*structure;

	structure = malloc(1 * sizeof(t_list));
	if (!structure)
		return (NULL);
	structure->content = content;
	structure->next = NULL;
	return (structure);
}
