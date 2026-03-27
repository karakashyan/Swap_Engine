/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: arptadev <arptadev@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2026/03/24 14:44:16 by arptadev          #+#    #+#             */
/*   Updated: 2026/03/24 14:44:16 by arptadev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	parse_options(int argc, char **argv, int *bench)
{
	int i;
	int flag;

	*bench = 0;
	flag = 3;
	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) == 0)
		{
			if (ft_strncmp(argv[i], "--bench", 8) == 0)
				*bench = 1;
			else if (ft_strncmp(argv[i], "--simple", 9) == 0)
				flag = 0;
			else if (ft_strncmp(argv[i], "--medium", 9) == 0)
				flag = 1;
			else if (ft_strncmp(argv[i], "--complex", 10) == 0)
				flag = 2;
			else if (ft_strncmp(argv[i], "--adaptive", 11) == 0)
				flag = 3;
			else
			{
				write(2, "Error\n", 6);
				return (-1);
			}
		}
		i++;
	}
	return (flag);
}

static void	run_sort(t_data *data, int flag)
{
	if (flag == 0)
		insertion_sort(data);
	else if (flag == 1)
		chunk_sort(data);
	else if (flag == 2)
		radix_sort(data);
	else
		adaptive_sort(data);
}

int	main(int argc, char **argv)
{
	t_data *data;
	char **arg;
	char *joined;
	double disorder;
	int flag;
	int bench;

	if (argc < 2)
		return (0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	flag = parse_options(argc, argv, &bench);
	if (flag == -1)
		return (1);
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
	//normalize(data->a);
	//print_stack(data->a);
	disorder = compute_disorder(data->a);
	run_sort(data, flag);
	if (bench)
		print_bench(data, disorder, flag);
	//print_stack(data->a);
	free_all(data, arg);
	return (0);
}
