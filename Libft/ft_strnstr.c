/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 20:48:42 by ekarakas          #+#    #+#             */
/*   Updated: 2026/02/02 22:12:08 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int main(void)
{
    const char *big = "Hello world!";
    const char *little = "world";

    char *res1 = ft_strnstr(big, little, 12);
    char *res2 = ft_strnstr(big, little, 5);
    char *res3 = ft_strnstr(big, "", 10);

    printf("Test 1: %s\n", res1 ? res1 : "NULL");
    printf("Test 2: %s\n", res2 ? res2 : "NULL");
    printf("Test 3: %s\n", res3 ? res3 : "NULL");

    return 0;
}*/
