/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <ekarakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:40:14 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/26 17:31:38 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_op(t_data *data, char *op)
{
    data->silent = 1;
	if (ft_strncmp(op, "sa\n", 3) == 0)
		sa(data);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		sb(data);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		ss(data);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		pa(data);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		pb(data);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		ra(data);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rb(data);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		rr(data);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		rra(data);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		rrb(data);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		rrr(data);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

static void	read_and_apply(t_data *data)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		apply_op(data, line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**arg;
	char	*joined;

	if (argc < 2)
		return (0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	data->silent = 1;
	joined = join_nums(argc, (char const **)argv);
	if (!joined)
	{
		write(2, "Error\n", 6);
		free_all(data, NULL);
		return (1);
	}
	arg = ft_split(joined, ' ');
	free(joined);
	if (!arg || fill_stack(data, arg) < 0)
	{
		free_all(data, arg);
		return (1);
	}
	normalize(data->a);
	read_and_apply(data);
	if (is_sorted(data->a) && !data->b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(data, arg);
	return (0);
}
