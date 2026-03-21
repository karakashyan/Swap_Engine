/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <ekarakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 19:24:48 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/21 16:52:52 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int	min;
	int	min_pos;
	int	i;

	i = 0;
	min = stack->value;
	min_pos = 0;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_pos = i;
		}
		i++;
		stack = stack->next;
	}
	return (min_pos);
}

void	sort_three(t_data *data)
{
	int	x;
	int	y;
	int	z;

	x = data->a->value;
	y = data->a->next->value;
	z = data->a->next->next->value;
	if (x > y && x > z)
		ra(data);
	else if (y > x && y > z)
		rra(data);
	if (data->a->value > data->a->next->value)
		sa(data);
}

void    insertion_sort(t_data *data)
{
    int    size;
    int    min_pos;

    size = stack_size(data->a);
    if (size < 2)
        return ;
    if (size == 2)
    {
		if (data->a->value > data->a->next->value)
        	sa(data);
        return ;
    }
    while (size > 3)
    {
        min_pos = find_min(data->a);
        bring_to_top(data, min_pos, size);
        pb(data);
        size--;
    }
    sort_three(data);
    while (data->b)
        pa(data);
}

void	normalize(t_stack *stack)
{
	t_stack	*cur;
	t_stack	*tmp;
	int		pos;

	cur = stack;
	while (cur)
	{
		pos = 0;
		tmp = stack;
		while (tmp)
		{
			if (tmp->value < cur->value)
				pos++;
			tmp = tmp->next;
		}
		cur->index = pos;
		cur = cur->next;
	}
}
