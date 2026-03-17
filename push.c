/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <ekarakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:55:04 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/17 23:01:24 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	while (stack != NULL)
	{
		printf("%d, ", stack->value);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_data *data;
	int i;

	if (argc < 2)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->a = NULL;
	data->b = NULL;
	i = argc - 1;
	while (i >= 1)
	{
		// parsing
		// ft_atoi
		push_front(&data->a, ft_atoi(argv[i]));
		i--;
	}
	print_stack(data->a);
    return (0);
}