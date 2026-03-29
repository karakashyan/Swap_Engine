/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arptadev <arptadev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:18:39 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/29 11:14:54 by arptadev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_len(long n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*res;

	nb = n;
	len = count_len(nb);
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (nb < 0)
		nb = -nb;
	while (len >= 0)
	{
		res[len] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
