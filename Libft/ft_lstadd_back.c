/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:44:02 by ekarakas          #+#    #+#             */
/*   Updated: 2026/02/11 19:02:02 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}
/*
int	main()
{
	t_list *p1 = ft_lstnew("Hi");
	t_list *p2 = ft_lstnew("My");
	t_list *p3 = ft_lstnew("Friend");

	p1->next = p2;

	ft_lstadd_back(&p1, p3);
	printf("%s",(char *)ft_lstlast(p1)->content);
}*/
