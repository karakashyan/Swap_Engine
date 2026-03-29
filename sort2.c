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

static int	find_max(t_stack *stack)
{
	int	max_idx;
	int	max_pos;
	int	i;

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

static int	count_chunk(t_stack *stack, int min, int max)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->index >= min && stack->index < max)
			count++;
		stack = stack->next;
	}
	return (count);
}

static void	push_chunk_to_b(t_data *data, int chunk_start, int chunk_end)
{
	int	count;

	count = count_chunk(data->a, chunk_start, chunk_end);
	while (count > 0)
	{
		if (data->a->index >= chunk_start && data->a->index < chunk_end)
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
}

void	chunk_sort(t_data *data)
{
	int	size;
	int	chunk_size;
	int	chunk;
	int	i;

	size = stack_size(data->a);
	if (size <= 100)
		chunk_size = 12;
	else
		chunk_size = 35;
	normalize(data->a);
	chunk = 0;
	while (chunk * chunk_size < size)
	{
		push_chunk_to_b(data, chunk * chunk_size, (chunk + 1) * chunk_size);
		chunk++;
	}
	while (data->b)
	{
		i = find_max(data->b);
		bring_to_top(data, i, stack_size(data->b), 1);
		pa(data);
	}
}

void	adaptive_sort(t_data *data)
{
	double	disorder;
	int		size;

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
		return (sort_three(data));
	else if (size <= 10)
		return (insertion_sort(data));
	disorder = compute_disorder(data->a);
	if (disorder < 0.2)
		insertion_sort(data);
	else if (disorder < 0.5)
		chunk_sort(data);
	else
		radix_sort(data);
}
