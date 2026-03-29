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

static char	*append_arg(char *s, const char *arg)
{
	char	*temp;
	char	*result;

	if (!s)
		return (ft_strdup(arg));
	temp = ft_strjoin(s, " ");
	free(s);
	result = ft_strjoin(temp, arg);
	free(temp);
	return (result);
}

char	*join_nums(int argc, char const **argv)
{
	int		i;
	int		j;
	char	*s;

	i = 1;
	s = NULL;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == ' ')
			j++;
		if (argv[i][j] == '\0')
			return (free(s), NULL);
		if (ft_strncmp(argv[i], "--", 2) != 0)
			s = append_arg(s, argv[i]);
		i++;
	}
	return (s);
}
