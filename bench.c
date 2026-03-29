/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arptadev <arptadev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:37:52 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/29 18:17:32 by arptadev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	total_ops(t_data *data)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (i < 11)
		total += data->ops[i++];
	return (total);
}

static char	*get_strategy(int flag, double disorder)
{
	if (flag == 0)
		return ("Simple / O(n²)");
	if (flag == 1)
		return ("Medium / O(n√n)");
	if (flag == 2)
		return ("Complex / O(n log n)");
	if (disorder < 0.2)
		return ("Adaptive / O(n²)");
	if (disorder < 0.5)
		return ("Adaptive / O(n√n)");
	return ("Adaptive / O(n log n)");
}

static void	print_percent(double d, int fd)
{
	int	whole;
	int	frac;

	whole = (int)(d * 100);
	frac = (int)(d * 10000) % 100;
	ft_putnbr_fd(whole, fd);
	write(fd, ".", 1);
	if (frac < 10)
		write(fd, "0", 1);
	ft_putnbr_fd(frac, fd);
}

double	compute_disorder(t_stack *stack)
{
	int		mistakes;
	int		total_pairs;
	t_stack	*temp;

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

void	print_bench(t_data *data, double disorder, int flag)
{
	char		*strat;
	int			i;
	static char	*names[] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	strat = get_strategy(flag, disorder);
	write(2, "[bench] disorder: ", 18);
	print_percent(disorder, 2);
	write(2, "%\n[bench] strategy: ", 20);
	write(2, strat, ft_strlen(strat));
	write(2, "\n[bench] total_ops: ", 20);
	ft_putnbr_fd(total_ops(data), 2);
	write(2, "\n[bench] ", 9);
	i = 0;
	while (i < 11)
	{
		write(2, names[i], ft_strlen(names[i]));
		write(2, ": ", 2);
		ft_putnbr_fd(data->ops[i], 2);
		write(2, " ", 1);
		if (i == 4)
			write(2, "\n[bench] ", 9);
		i++;
	}
	write(2, "\n", 1);
}
