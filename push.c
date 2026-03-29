/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arptadev <arptadev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 16:55:04 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/29 20:22:52 by arptadev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_data *data)
{
	int	idx;

	if (!data->b)
		return ;
	idx = data->b->index;
	push_front(&data->a, stack_pop(&data->b), idx);
	data->ops[PA]++;
	if (!data->silent)
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
	if (!data->silent)
		write(1, "pb\n", 3);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

bool	dub_check(int n, t_stack *a)
{
	while (a != NULL)
	{
		if (a->value == n)
			return (false);
		a = a->next;
	}
	return (true);
}
