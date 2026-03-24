/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: ekarakas <ekarakas@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2026/03/20 17:47:47 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/21 14:58:38 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	rotate(t_stack **stack)
{
	t_stack *top;
	t_stack *last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	top = *stack;
	*stack = top->next;
	(*stack)->prev = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = top;
	top->prev = last;
	top->next = NULL;
}

void	ra(t_data *data)
{
	rotate(&data->a);
	data->ops[RA]++;
	write(1, "ra\n", 3);
}

void	rb(t_data *data)
{
	rotate(&data->b);
	data->ops[RB]++;
	write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	rotate(&data->a);
	rotate(&data->b);
	data->ops[RR]++;
	write(1, "rr\n", 3);
}