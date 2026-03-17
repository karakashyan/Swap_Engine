/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:47:29 by ekarakas          #+#    #+#             */
/*   Updated: 2026/02/07 20:58:35 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
/*
int	main(void)
{
    unsigned char *p;

    printf("Test 1: nmemb=5, size=4\n");
    p = ft_calloc(5, 4);
    if (!p)
        printf("FAIL: NULL\n");
    else
    {
        for (int i = 0; i < 20; i++)
            printf("%02X ", p[i]);
        printf("\n");
        free(p);
    }

    printf("\nTest 2: perepolnenie\n");
    p = ft_calloc(SIZE_MAX, 2);
    if (!p)
        printf("OK: overflow zashita rabotaet\n");
    else
        printf("FAIL: doljno byt NULL\n");

    printf("\nTest 3: nmemb=0\n");
    p = ft_calloc(0, 10);
    printf("pointer: %p\n", p);
    free(p);

    return 0;
}*/
