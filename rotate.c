/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arptadev <arptadev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:24:24 by arptadev          #+#    #+#             */
/*   Updated: 2026/03/29 18:24:24 by arptadev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack		*top;
	t_stack		*last;

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
	if (!data->silent)
		write(1, "ra\n", 3);
}

void	rb(t_data *data)
{
	rotate(&data->b);
	data->ops[RB]++;
	if (!data->silent)
		write(1, "rb\n", 3);
}

void	rr(t_data *data)
{
	rotate(&data->a);
	rotate(&data->b);
	data->ops[RR]++;
	if (!data->silent)
		write(1, "rr\n", 3);
}
