/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: arptadev <arptadev@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2026/03/24 14:45:56 by arptadev          #+#    #+#             */
/*   Updated: 2026/03/24 14:45:56 by arptadev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	find_min(t_stack *stack)
{
	int min;
	int min_pos;
	int i;

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
	int x;
	int y;
	int z;

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
	int size;
	int min_pos;

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
		{
			pa(data);
			return ;
		}
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
	t_stack *cur;
	t_stack *tmp;
	int pos;

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

int	count_chunk(t_stack *stack, int min, int max)
{
	int count;

	count = 0;
	while (stack)
	{
		if (stack->index >= min && stack->index < max)
			count++;
		stack = stack->next;
	}
	return (count);
}

void	radix_sort(t_data *data)
{
	int max_bits;
	int size;
	int i;

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

static int	cost_to_top(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (size - pos);
}

int	find_cheapest(t_stack *stack)
{
	int size;
	int best_pos;
	int best_cost;
	int best_idx;
	int i;
	int cost;

	size = stack_size(stack);
	best_pos = 0;
	best_cost = size;
	best_idx = -1;
	i = 0;
	while (stack)
	{
		cost = cost_to_top(i, size);
		if (cost < best_cost || (cost == best_cost && stack->index > best_idx))
		{
			best_cost = cost;
			best_pos = i;
			best_idx = stack->index;
		}
		i++;
		stack = stack->next;
	}
	return (best_pos);
}

void	chunk_sort(t_data *data)
{
	int size;
	int chunk_size;
	int chunk;
	int count;
	int i;

	size = stack_size(data->a);
	if (size <= 100)
		chunk_size = 25;
	else
		chunk_size = 50;
	normalize(data->a);
	chunk = 0;
	while (chunk * chunk_size < size)
	{
		count = count_chunk(data->a, chunk * chunk_size, (chunk + 1)
				* chunk_size);
		while (count > 0)
		{
			if (data->a->index >= chunk * chunk_size && data->a->index < (chunk
					+ 1) * chunk_size)
			{
				pb(data);
				count--;
				if (data->b && data->b->next
					&& data->b->index < data->b->next->index)
					sb(data);
			}
			else
				ra(data);
		}
		chunk++;
	}
	while (data->b)
	{
		i = find_cheapest(data->b);
		bring_to_top(data, i, stack_size(data->b), 1);
		pa(data);
	}
}

double	compute_disorder(t_stack *stack)
{
	int mistakes;
	int total_pairs;
	t_stack *temp;

	if (!stack)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	while (stack->next)
	{
		temp = stack->next;
		while (temp)
		{
			total_pairs++;
			if (stack->value > temp->value)
				mistakes++;
			temp = temp->next;
		}
		stack = stack->next;
	}
	return ((double)mistakes / total_pairs);
}

void	adaptive_sort(t_data *data)
{
	double disorder;
	int size;

	size = stack_size(data->a);
	if (size <= 1 || is_sorted(data->a))
		return ;
	if (size == 2)
	{
		if (data->a->value > data->a->next->value)
			sa(data);
		return ;
	}
	if (size == 3)
	{
		sort_three(data);
		return ;
	}
	else if (size <= 10)
	{
		insertion_sort(data);
		return ;
	}
	disorder = compute_disorder(data->a);
	if (disorder < 0.2)
		insertion_sort(data);
	else if (disorder < 0.5)
		chunk_sort(data);
	else
		radix_sort(data);
}