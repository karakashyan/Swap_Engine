/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 22:12:58 by ekarakas          #+#    #+#             */
/*   Updated: 2026/02/07 20:43:26 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
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
	}
	return ((int)(sign * number));
}
/*
int	main(void)
{
    printf("ft_atoi(\"42\") = %d\n", ft_atoi("42"));
    printf("ft_atoi(\"   42\") = %d\n", ft_atoi("   42"));
    printf("ft_atoi(\"\\t\\n  -15\") = %d\n", ft_atoi("\t\n  -15"));
    printf("ft_atoi(\"+7\") = %d\n", ft_atoi("+7"));
    printf("ft_atoi(\"++7\") = %d\n", ft_atoi("++7"));
    printf("ft_atoi(\"--7\") = %d\n", ft_atoi("--7"));
    printf("ft_atoi(\"12abc\") = %d\n", ft_atoi("12abc"));
    printf("ft_atoi(\"abc12\") = %d\n", ft_atoi("abc12"));
    printf("ft_atoi(\"- 12\") = %d\n", ft_atoi("- 12"));
    printf("ft_atoi(\"+\") = %d\n", ft_atoi("+"));
    printf("ft_atoi(\"0\") = %d\n", ft_atoi("0"));
    printf("ft_atoi(\"-0\") = %d\n", ft_atoi("-0"));
    printf("ft_atoi(\"2147483647\") = %d\n", ft_atoi("2147483647"));
    printf("ft_atoi(\"-2147483648\") = %d\n", ft_atoi("-2147483648"));
    return 0;
}*/
