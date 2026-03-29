/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arptadev <arptadev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:40:14 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/29 20:02:54 by arptadev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	trim_newline(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			s[i] = '\0';
			return ;
		}
		i++;
	}
}

static int	apply_op(t_data *data, char *op)
{
	if (ft_strcmp(op, "rra") == 0)
		return (rra(data), 1);
	if (ft_strcmp(op, "rrb") == 0)
		return (rrb(data), 1);
	if (ft_strcmp(op, "rrr") == 0)
		return (rrr(data), 1);
	if (ft_strcmp(op, "sa") == 0)
		return (sa(data), 1);
	if (ft_strcmp(op, "sb") == 0)
		return (sb(data), 1);
	if (ft_strcmp(op, "ss") == 0)
		return (ss(data), 1);
	if (ft_strcmp(op, "pa") == 0)
		return (pa(data), 1);
	if (ft_strcmp(op, "pb") == 0)
		return (pb(data), 1);
	if (ft_strcmp(op, "ra") == 0)
		return (ra(data), 1);
	if (ft_strcmp(op, "rb") == 0)
		return (rb(data), 1);
	if (ft_strcmp(op, "rr") == 0)
		return (rr(data), 1);
	return (0);
}

static void	read_and_apply(t_data *data)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		trim_newline(line);
		if (line[0] && !apply_op(data, line))
		{
			free(line);
			write(2, "Error\n", 6);
			free_all(data, NULL);
			exit(1);
		}
		line = get_next_line(0);
	}
	if (is_sorted(data->a) && !data->b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static char	**init_data(int argc, char **argv, t_data *data)
{
	char	*joined;
	char	**arg;

	joined = join_nums(argc, (char const **)argv);
	if (!joined)
	{
		write(2, "Error\n", 6);
		free_all(data, NULL);
		return (NULL);
	}
	arg = ft_split(joined, ' ');
	free(joined);
	if (!arg || !arg[0])
	{
		write(2, "Error\n", 6);
		free_all(data, arg);
		return (NULL);
	}
	if (fill_stack(data, arg) < 0)
	{
		free_all(data, arg);
		return (NULL);
	}
	return (arg);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**arg;

	if (argc < 2)
		return (0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	data->silent = 1;
	arg = init_data(argc, argv, data);
	if (!arg)
		return (1);
	read_and_apply(data);
	return (free_all(data, arg), 0);
}
