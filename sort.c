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

int find_max(t_stack *stack)
{
    int max_idx;
    int max_pos;
    int i;

    i = 0;
    max_idx = stack->index;
    max_pos = 0;
    while (stack)
    {
        if (stack->index > max_idx)
        {
            max_idx = stack->index;
            max_pos = i;
        }
        i++;
        stack = stack->next;
    }
    return (max_pos);
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

void	chunk_sort(t_data *data)
{
	int size;
	int chunk_size;
	int chunk;
	int count;
	int i;

	size = stack_size(data->a);
	if (size <= 100)
		chunk_size = 12;
	else
		chunk_size = 35;
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
		i = find_max(data->b);
		bring_to_top(data, i, stack_size(data->b), 1);
		pa(data);
	}
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