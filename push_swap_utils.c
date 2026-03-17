/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <ekarakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:34:20 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/17 22:39:53 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_front(t_stack **stack, int value)
{
	t_stack	*node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->value = value;
	node->prev = NULL;
	node->next = NULL;
	node->next = *stack;
	if (*stack)
		(*stack)->prev = node;
	*stack = node;
}

// void	push_back(t_stack **stack, int value)
// {
// 	t_stack *node;
// 	t_stack	*last;

// 	if (!stack)
// 		return ;
// 	node = malloc(sizeof(t_stack));
// 	if (!node)
// 		return ;
// 	node->value = value;
// 	node->prev = NULL;
// 	node->next = NULL;

// 	if (*stack)
// 	{
// 		last = *stack;
// 		while (last->next != NULL)
// 			last = last->next;
// 		last->next = node;
// 		node->prev = last;
// 	}
// 	else
// 		*stack = node;
// }

int	stack_pop(t_stack **stack)
{
	int		first;
	t_stack	*temp;

	first = (*stack)->value;
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
	return (first);
}
