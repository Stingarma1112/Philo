/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsaumon <lsaumon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:06:24 by lsaumon           #+#    #+#             */
/*   Updated: 2024/03/08 03:31:07 by lsaumon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static t_list	*create_node(void *content, void (*del)(void *))
{
	t_list	*new_node;

	new_node = ft_lstnew(content);
	if (!new_node)
	{
		del(content);
		return (NULL);
	}
	return (new_node);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*stock;
	void	*content;

	if (!lst || !del || !f)
		return (NULL);
	content = (*f)(lst->content);
	new_lst = create_node(content, del);
	if (!new_lst)
		return (NULL);
	stock = new_lst;
	lst = lst->next;
	while (lst)
	{
		content = (*f)(lst->content);
		stock->next = create_node(content, del);
		if (!stock->next)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		stock = stock->next;
		lst = lst->next;
	}
	return (new_lst);
}
