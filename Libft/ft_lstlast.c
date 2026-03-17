/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:39:04 by ekarakas          #+#    #+#             */
/*   Updated: 2026/02/11 16:07:09 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int main(void)
{
	t_list *a;
	t_list *b;
	t_list *c;

	a = ft_lstnew("Hi");
	b = ft_lstnew("Hello");
	c = ft_lstnew("Last");

	a->next = b;
	b->next = c; 

	printf("%s\n", (char *)ft_lstlast(a)->content);

	return (0);
}*/
