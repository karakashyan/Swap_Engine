/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arptadev <arptadev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 14:05:43 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/29 11:15:33 by arptadev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_args(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	fill_stack(t_data *data, char **arg)
{
	int	size;
	int	i;
	int	number;

	size = count_args(arg);
	i = size;
	while (i--)
	{
		if (!parsing(arg[i]))
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		number = atoi_check(arg[i]);
		if (!dub_check(number, data->a))
		{
			write(2, "Error\n", 6);
			return (-1);
		}
		push_front(&data->a, number, 0);
	}
	return (size);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	free_all(t_data *data, char **arg)
{
	int	i;

	if (arg)
	{
		i = 0;
		while (arg[i])
			free(arg[i++]);
		free(arg);
	}
	if (!data)
		return ;
	free_stack(&data->a);
	free_stack(&data->b);
	free(data);
}
