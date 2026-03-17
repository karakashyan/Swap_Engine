/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekarakas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:46:06 by ekarakas          #+#    #+#             */
/*   Updated: 2026/02/07 15:42:15 by ekarakas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static char my_func(unsigned int i, char c)
{
	i++;
	return (c + 1);
}*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	if (!s || !f)
		return (NULL);
	new = (char *)malloc(ft_strlen(s) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = f(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
/*
int main(void)
{
    char *s = "abcd";
    char *res;

    res = ft_strmapi(s, my_func);
    if (!res)
        return (1);

    printf("Original: %s\n", s);
    printf("Result:   %s\n", res);

    free(res);
    return (0);
}*/
