/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <ekarakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:55:04 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/23 18:44:12 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_data *data)
{
	int	idx;
	
	if (!data->a)
		return ;
	idx = data->a->index;
	push_front(&data->b, stack_pop(&data->a), idx);
	write(1, "pb\n", 3);
}

void	pa(t_data *data)
{
	int	idx;
	
	if (!data->b)
		return ;
	idx = data->b->index;
	push_front(&data->a, stack_pop(&data->b), idx);
	write(1, "pa\n", 3);
}