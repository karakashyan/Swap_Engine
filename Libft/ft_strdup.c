/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:58:36 by ekarakas          #+#    #+#             */
/*   Updated: 2026/02/07 20:59:30 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	i;

	p = (char *)malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
/*int	main(void)
{
    char *a = "42 School";
    char *b = ft_strdup(a);

    printf("a: %s\n", a);
    printf("b: %s\n", b);

    b[0] = 'X';
    printf("after:\n");
    printf("a: %s\n", a);
    printf("b: %s\n", b);

    free(b);
}*/
