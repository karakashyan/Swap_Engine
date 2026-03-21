/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <ekarakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:55:04 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/21 15:35:36 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_data *data)
{
	if (!data->a)
		return ;
	push_front(&data->b, stack_pop(&data->a));
	write(1, "pb\n", 3);
}

void	pa(t_data *data)
{
	if (!data->b)
		return ;
	push_front(&data->a, stack_pop(&data->b));
	write(1, "pa\n", 3);
}