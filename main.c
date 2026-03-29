/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arptadev <arptadev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 14:00:00 by arptadev          #+#    #+#             */
/*   Updated: 2026/03/29 14:00:00 by arptadev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_sort(t_data *data, int flag, int bench)
{
	double		disorder;

	disorder = compute_disorder(data->a);
	if (flag == 0)
		insertion_sort(data);
	else if (flag == 1)
		chunk_sort(data);
	else if (flag == 2)
		radix_sort(data);
	else
		adaptive_sort(data);
	if (bench)
		print_bench(data, disorder, flag);
}

static char	**prepare_stack(int argc, char **argv, t_data *data)
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
	if (!arg || fill_stack(data, arg) < 0)
	{
		free_all(data, arg);
		return (NULL);
	}
	return (arg);
}

int	parse_options(int argc, char **argv, int *bench)
{
	int		flag;

	*bench = 0;
	flag = 3;
	while (--argc > 0)
	{
		argv++;
		if (ft_strncmp(*argv, "--", 2) == 0)
		{
			if (ft_strncmp(*argv, "--bench", 8) == 0)
				*bench = 1;
			else if (ft_strncmp(*argv, "--simple", 9) == 0)
				flag = 0;
			else if (ft_strncmp(*argv, "--medium", 9) == 0)
				flag = 1;
			else if (ft_strncmp(*argv, "--complex", 10) == 0)
				flag = 2;
			else if (ft_strncmp(*argv, "--adaptive", 11) == 0)
				flag = 3;
			else
				return (write(2, "Error\n", 6), -1);
		}
	}
	return (flag);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**arg;
	int		flag;
	int		bench;

	if (argc < 2)
		return (0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	flag = parse_options(argc, argv, &bench);
	if (flag == -1)
		return (1);
	arg = prepare_stack(argc, argv, data);
	if (!arg)
		return (1);
	run_sort(data, flag, bench);
	free_all(data, arg);
	return (0);
}
