/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arptadev <arptadev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:24:52 by arptadev          #+#    #+#             */
/*   Updated: 2026/03/29 18:24:52 by arptadev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int		temp;

	if (!stack || !stack->next)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	sa(t_data *data)
{
	swap(data->a);
	data->ops[SA]++;
	if (!data->silent)
		write(1, "sa\n", 3);
}

void	sb(t_data *data)
{
	swap(data->b);
	data->ops[SB]++;
	if (!data->silent)
		write(1, "sb\n", 3);
}

void	ss(t_data *data)
{
	swap(data->a);
	swap(data->b);
	data->ops[SS]++;
	if (!data->silent)
		write(1, "ss\n", 3);
}
