/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 15:02:35 by ekarakas          #+#    #+#             */
/*   Updated: 2026/02/11 18:10:56 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
void	del(void *x)
{
	free(x);
}

int	main()
{
	t_list *a = ft_lstnew(ft_strdup("Hello"));
	t_list *b = ft_lstnew(ft_strdup("My"));
	t_list *c = ft_lstnew(ft_strdup("Friend"));

	a->next = b;
	b->next = c;

	a->next = b->next;
	ft_lstdelone(b, del);

	t_list *temp = a;
	while (temp != NULL)
	{
		printf("%s", (char *)temp->content);
		temp = temp->next;
	}
	return (0);
}*/
