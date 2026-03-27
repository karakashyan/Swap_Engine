/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <ekarakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:37:52 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/27 21:46:45 by ekarakas         ###   ########.fr       */
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

static char	*get_strategy(int flag)
{
	if (flag == 0)
		return ("Simple O(n^2)");
	if (flag == 1)
		return ("Medium O(n*sqrt(n))");
	if (flag == 2)
		return ("Complex O(n log n)");
	return ("Adaptive");
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

void	print_bench(t_data *data, double disorder, int flag)
{
	static char	*names[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};
	char		*strat;
	int			i;

	strat = get_strategy(flag);
	write(2, "[bench] disorder: ", 18);
	print_percent(disorder, 2);
	write(2, "%\n", 2);
	write(2, "[bench] strategy: ", 18);
	write(2, strat, ft_strlen(strat));
	write(2, "\n", 1);
	write(2, "[bench] total_ops: ", 19);
	ft_putnbr_fd(total_ops(data), 2);
	write(2, "\n", 1);
	write(2, "[bench] ", 8);
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