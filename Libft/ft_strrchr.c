/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 20:18:42 by ekarakas          #+#    #+#             */
/*   Updated: 2026/02/07 20:38:11 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p)
		p++;
	if ((unsigned char)c == '\0')
		return (p);
	while (p != s)
	{
		if (*(p - 1) == (unsigned char)c)
			return (p - 1);
		p--;
	}
	return (NULL);
}
