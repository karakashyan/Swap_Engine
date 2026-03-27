/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <ekarakas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:40:37 by ekarakas          #+#    #+#             */
/*   Updated: 2026/03/27 19:51:50 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*x;
	size_t	ls1;
	size_t	ls2;

	if (!s1 || !s2)
		return (NULL);
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	x = (char *)malloc(ls1 + ls2 + 1);
	if (!x)
		return (NULL);
	ft_memcpy(x, s1, ls1);
	ft_memcpy(x + ls1, s2, ls2);
	x[ls1 + ls2] = '\0';
	return (x);
}
