/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arptadev <arptadev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:44:16 by arptadev          #+#    #+#             */
/*   Updated: 2026/03/24 14:44:16 by arptadev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	get_flag(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--simple", 9) == 0)
			return (0);
		if (ft_strncmp(argv[i], "--medium", 9) == 0)
			return (1);
		if (ft_strncmp(argv[i], "--complex", 10) == 0)
			return (2);
		if (ft_strncmp(argv[i], "--adaptive", 11) == 0)
			return (3);
		i++;
	}
	return (3);
}

int	main(int argc, char **argv)
{
	t_data *data;
	char **arg;
	int i;
	int number;
	int size;
	int flag;

	if (argc < 2)
		return (0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
    	return (1);
	flag = get_flag(argc, argv);
	if (flag != 3 || ft_strncmp(argv[1], "--", 2) == 0)
		arg = ft_split(join_args(argc - 1, (char const **)argv + 1), ' ');
	else
		arg = ft_split(join_args(argc, (char const **)argv), ' ');
	size = count_args(arg);
	i = size;
	while (i--)
	{
		if (!parsing(arg[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		number = atoi_check(arg[i]);
		if (!dub_check(number, data->a))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		push_front(&data->a, number, 0);
	}
	if (size == 1 || is_sorted(data->a))
		return (0);
	if (size == 2)
	{
		if (data->a->value > data->a->next->value)
			sa(data);
		return (0);
	}
	if (size == 3)
		sort_three(data);
	else if (size <= 5 || flag == 0)
		insertion_sort(data);
	else if (flag == 1)
		chunk_sort(data);
	else if (flag == 2)
		radix_sort(data);
	else
		adaptive_sort(data);
	return (0);
}