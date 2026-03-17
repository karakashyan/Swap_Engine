/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 14:16:17 by ekarakas          #+#    #+#             */
/*   Updated: 2026/02/10 20:26:34 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*
int main(void)
{
	t_list *node1;
	t_list *node2;
	t_list *node3;

	node1 = ft_lstnew("Hi");
	node2 = ft_lstnew("My");
	node3 = ft_lstnew("Friend");

	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;

	printf("%d", ft_lstsize(node1));

	t_list *temp = node1;
	t_list *next;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	node1 = NULL;
	return (0);
}*/
