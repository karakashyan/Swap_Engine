/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <ekarakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 16:40:14 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/27 22:43:55 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

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
		rra(data);
	else if (ft_strcmp(op, "rrb") == 0)
		rrb(data);
	else if (ft_strcmp(op, "rrr") == 0)
		rrr(data);
	else if (ft_strcmp(op, "sa") == 0)
		sa(data);
	else if (ft_strcmp(op, "sb") == 0)
		sb(data);
	else if (ft_strcmp(op, "ss") == 0)
		ss(data);
	else if (ft_strcmp(op, "pa") == 0)
		pa(data);
	else if (ft_strcmp(op, "pb") == 0)
		pb(data);
	else if (ft_strcmp(op, "ra") == 0)
		ra(data);
	else if (ft_strcmp(op, "rb") == 0)
		rb(data);
	else if (ft_strcmp(op, "rr") == 0)
		rr(data);
	else
		return (0);
	return (1);
}

static void	read_and_apply(t_data *data)
{
	char	*line;

	while ((line = get_next_line(0)))
	{
		trim_newline(line);
		if (line[0] && !apply_op(data, line))
		{
			free(line);
			write(2, "Error\n", 6);
			free_all(data, NULL);
			exit(1);
		}
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
	read_and_apply(data);
	if (is_sorted(data->a) && !data->b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(data, arg);
	return (0);
}
