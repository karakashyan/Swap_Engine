/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <ekarakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:36:41 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/21 16:20:07 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	char	**arg;
	int		i;
	int		number;

	if (argc < 2)
		return (0);
	data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	data->a = NULL;
	data->b = NULL;
	arg = ft_split(join_args(argc, (char const **)argv), ' ');
	i = count_args(arg) - 1;
	while (i >= 0)
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
		push_front(&data->a, number);
		i--;
	}
	normalize(data->a);
	print_stack(data->a);
	chunk_sort(data);
	normalize(data->a);
	print_stack(data->a);
	
	return (0);
}