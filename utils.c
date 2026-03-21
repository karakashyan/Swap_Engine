/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <ekarakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:34:20 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/21 16:52:22 by ekarakas         ###   ########.fr       */
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
	node->next = *stack;
	if (*stack)
		(*stack)->prev = node;
	*stack = node;
}

void	bring_to_top(t_data *data, int pos, int size)
{
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(data);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(data);
			pos++;
		}
	}
}

int	stack_size(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

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

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("%d, ", stack->value);
		stack = stack->next;
	}
}
