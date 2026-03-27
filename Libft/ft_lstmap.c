/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <ekarakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:23:48 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/27 19:57:44 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*clear_and_null(t_list **lst, void (*del)(void *), void *content)
{
	if (content)
		del(content);
	ft_lstclear(lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content)
			return (clear_and_null(&new_list, del, NULL));
		new_node = ft_lstnew(new_content);
		if (!new_node)
			return (clear_and_null(&new_list, del, new_content));
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
