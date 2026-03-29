/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arptadev <arptadev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 18:24:35 by arptadev          #+#    #+#             */
/*   Updated: 2026/03/29 18:24:35 by arptadev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stack *stack)
{
	int		min;
	int		min_pos;
	int		i;

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
	int		x;
	int		y;
	int		z;

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

void	insertion_sort(t_data *data)
{
	int		size;
	int		min_pos;

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
		bring_to_top(data, min_pos, size, 0);
		if (is_sorted(data->a))
			return (pa(data));
		else
			pb(data);
		size--;
	}
	sort_three(data);
	while (data->b)
		pa(data);
}

void	normalize(t_stack *stack)
{
	t_stack		*cur;
	t_stack		*tmp;
	int			pos;

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

void	radix_sort(t_data *data)
{
	int	max_bits;
	int	size;
	int	i;

	size = stack_size(data->a);
	max_bits = 0;
	normalize(data->a);
	while ((size - 1) >> max_bits)
	{
		i = size;
		while (i-- && data->a)
		{
			if ((data->a->index >> max_bits) & 1)
				ra(data);
			else
				pb(data);
		}
		while (data->b)
			pa(data);
		if (is_sorted(data->a))
			return ;
		max_bits++;
	}
}
