/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 17:45:50 by ekarakas          #+#    #+#             */
/*   Updated: 2026/02/07 19:45:25 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*int	main()
{
	unsigned char arr[5];
	ft_memset(arr, 'X', 5);
	ft_bzero(arr, 2);
	size_t	i;

	i = 0;
	while (i < 5)
	{
		printf("%c", arr[i]);
		i++;
	}
}*/
