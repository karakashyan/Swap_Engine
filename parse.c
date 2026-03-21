/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <ekarakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 16:18:43 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/21 16:19:48 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	parsing(char *value)
{
	int	i;

	if (!value)
		return (false);
	i = 0;
	if (value[0] == '-' || value[0] == '+')
		i++;
	if (!value[i])
		return (false);
	while (value[i])
	{
		if (!ft_isdigit(value[i]))
			return (false);
		i++;
	}
	return (true);
}

int	atoi_check(const char *nptr)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	sign = 1;
	number = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - '0');
		i++;
		if ((sign == 1 && number > 2147483647) || (sign == -1
				&& number > 2147483648))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	return ((int)(sign * number));
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

char	*join_args(int argc, char const **argv)
{
	int		i;
	char	*s;
	char	*temp;

	i = 2;
	s = ft_strdup(argv[1]);
	while (i < argc)
	{
		temp = ft_strjoin(s, " ");
		free(s);
		s = ft_strjoin(temp, argv[i]);
		free(temp);
		i++;
	}
	return (s);
}

int	count_args(char **s)
{
	int	i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}