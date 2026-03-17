/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 20:27:52 by ekarakas          #+#    #+#             */
/*   Updated: 2026/02/07 20:25:36 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int main(void)
{
    char a[10];
    char b[5];
    char c[1];
    char d[5];

    size_t r1 = ft_strlcpy(a, "hello", 10);
    size_t r2 = ft_strlcpy(b, "abcdef", 5);
    size_t r3 = ft_strlcpy(c, "hi", 1);
    size_t r4 = ft_strlcpy(d, "yo", 0);

    printf("a: \"%s\"  ret=%zu\n", a, r1); // hello, 5
    printf("b: \"%s\"  ret=%zu\n", b, r2); // abcd, 6
    printf("c: \"%s\"  ret=%zu\n", c, r3); // "", 2
    printf("d: (size=0) ret=%zu\n", r4);   // 2

    return (0);
}*/
