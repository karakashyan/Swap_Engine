/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 13:47:49 by ekarakas          #+#    #+#             */
/*   Updated: 2026/02/07 20:26:06 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	dst_len;

	d = 0;
	s = 0;
	while (d < size && dst[d])
		d++;
	dst_len = d;
	if (d == size)
		return (size + ft_strlen(src));
	while (src[s] && d < size - 1)
	{
		dst[d] = src[s];
		d++;
		s++;
	}
	dst[d] = '\0';
	return (dst_len + ft_strlen(src));
}
