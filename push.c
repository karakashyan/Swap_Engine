/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arptadev <arptadev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:55:04 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/24 16:26:00 by arptadev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	int idx;

	if (!data->b)
		return ;
	idx = data->b->index;
	push_front(&data->a, stack_pop(&data->b), idx);
	data->ops[PA]++;
	write(1, "pa\n", 3);
}

void	pb(t_data *data)
{
	int	idx;

	if (!data->a)
		return ;
	idx = data->a->index;
	push_front(&data->b, stack_pop(&data->a), idx);
	data->ops[PB]++;
	write(1, "pb\n", 3);
}
