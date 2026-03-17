/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 16:23:48 by ekarakas          #+#    #+#             */
/*   Updated: 2026/02/17 15:01:25 by ekarakas         ###   ########.fr       */
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
/*
void *double_number(void *content)
{
    int *num = (int *)content;
    int *new_num = malloc(sizeof(int));
    if (!new_num)
        return NULL;
    *new_num = (*num) * 2;
    return new_num;
}

void del_content(void *content)
{
    free(content);
}

void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d ", *(int *)lst->content);
        lst = lst->next;
    }
    printf("\n");
}

int main(void)
{
    t_list *lst = NULL;
    t_list *new_lst;
    int nums[] = {1, 2, 3};

    for (int i = 0; i < 3; i++)
    {
        int *val = malloc(sizeof(int));
        if (!val)
            return 1;
        *val = nums[i];
        ft_lstadd_back(&lst, ft_lstnew(val));
    }

    printf("Original list: ");
    print_list(lst);

    new_lst = ft_lstmap(lst, double_number, del_content);

    printf("Mapped list: ");
    print_list(new_lst);

    ft_lstclear(&lst, del_content);
    ft_lstclear(&new_lst, del_content);
    return 0;
}*/
