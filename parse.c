/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arptadev <arptadev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 13:10:58 by arptadev          #+#    #+#             */
/*   Updated: 2026/03/29 13:10:58 by arptadev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	parsing(char *value)
{
	int		i;

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

static void	check_overflow(int sign, long number)
{
	if ((sign == 1 && number > 2147483647) || (sign == -1
			&& number > 2147483648))
	{
		write(2, "Error\n", 6);
		exit(1);
	}
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
		check_overflow(sign, number);
		i++;
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

char	*join_nums(int argc, char const **argv)
{
	int		i;
	char	*s;
	char	*temp;

	i = 1;
	s = NULL;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--", 2) != 0 && argv[i][0] != '\0')
		{
			if (!s)
				s = ft_strdup(argv[i]);
			else
			{
				temp = ft_strjoin(s, " ");
				free(s);
				s = ft_strjoin(temp, argv[i]);
				free(temp);
			}
		}
		i++;
	}
	return (s);
}
