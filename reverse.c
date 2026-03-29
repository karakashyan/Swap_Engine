/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arptadev <arptadev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:23:10 by arptadev          #+#    #+#             */
/*   Updated: 2026/03/29 18:23:10 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

void	rra(t_data *data)
{
	reverse(&data->a);
	data->ops[RRA]++;
	if (!data->silent)
		write(1, "rra\n", 4);
}

void	rrb(t_data *data)
{
	reverse(&data->b);
	data->ops[RRB]++;
	if (!data->silent)
		write(1, "rrb\n", 4);
}

void	rrr(t_data *data)
{
	reverse(&data->a);
	reverse(&data->b);
	data->ops[RRR]++;
	if (!data->silent)
		write(1, "rrr\n", 4);
}
