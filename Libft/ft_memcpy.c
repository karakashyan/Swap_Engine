/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:56:34 by ekarakas          #+#    #+#             */
/*   Updated: 2026/02/18 15:14:06 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*f;
	size_t			i;

	if (!dest && !src && n > 0)
		return (NULL);
	p = (unsigned char *)dest;
	f = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		p[i] = f[i];
		i++;
	}
	return (dest);
}
